//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

/* TODO:
 * Thread manager and animations, currently for use with smart binds
 * Should smartBinds have absolute bind option?
 * Implement midiout
 * Create seperate header file(s) containing utilities
 * Use typedef to declare controller
     -change controller object in one spot and done
 * Create functional testmodel and testcontroller
 * Midi input from attached software (midi input from multiple sources) 
 */

//d_midi, d_route, d_parser
//FIXME TODO FIXME TODO FIXME TODO
//#define d_midi
//FIXME TODO FIXME TODO FIXME TODO

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include "RtMidi.h"
struct Reference
{
	Reference() {}
	Reference(int channel, int note, int value) :
		channel(channel), note(note), value(value) {}
	int channel, note, value;
};
class SendMidi
{
public:
	SendMidi(RtMidiOut * midiout) : midiout(midiout) {}
	void send(Reference _ref, int value)
	{
		//cout << _ref.channel << ", " << _ref.note << ", " << value << endl;
		vector<unsigned char> out_message;
		out_message.push_back(_ref.channel);
		out_message.push_back(_ref.note);
		out_message.push_back(value);
		for (unsigned int i=0; i!=out_message.size(); ++i)
			out_message[i] += 0;
#ifndef d_route
		midiout->sendMessage( &out_message );
#endif
		cout << "Sending midi: " << _ref.channel << ", " << _ref.note << ", " << value << endl;
	}
private:
	RtMidiOut * midiout;
};
#include "Models/testmodel.cpp"
#include "Models/feedbackClass.cpp"
int midiBehavior;
vector<pair<int,int>> currentGroupPage(10); //current page, last page
map<pair<int, int>, int> groups;
#include "Controllers/apc80.cpp"
//:::::::::::::::::::::::::::
typedef APC80 Controller;
//typedef JAMESCONTROLLERCLASS Controller;
//:::::::::::::::::::::::::::
#include "mapping.cpp"

int channel, note, opGroup, page, value;

RtMidiIn *midiin = new RtMidiIn();
RtMidiOut *midiout = new RtMidiOut();
SendMidi sendmidi {midiout};
Controller controller {&sendmidi};
midimap mapping = parse_mapping(&controller);

void route(double deltatime, vector<unsigned char> * message, void * userData)
{
	channel = (int)message->at(0) - 128;
	note = (int)message->at(1);
	opGroup = groups[{channel, note}];
	page = currentGroupPage[opGroup].first;
	value = (int)message->at(2);
	
#ifdef d_midi
	unsigned int nBytes = message->size();
	for (unsigned int i=0; i!=nBytes-1; ++i)
		cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
	if (nBytes > 0)
		cout << "stamp = " << deltatime << endl;
#endif
	auto op = mapping[page][channel][note];
	if (op.name == "")
		return;
	if (midiBehavior == 1)
	{
		(controller.*op.ptr)(value, op.params);
		//cout << "Return code: " << returnVal << endl;
	} else if (midiBehavior == 2) {
		if (op.name == "smartBind") //exit bind mode
			controller.smartBind(value, vector<int> { 0, 0 });
		else if (op.name == "ascending")
			controller.smartBind(value, vector<int> { 2, 0 });
		else if (op.name == "descending")
			controller.smartBind(value, vector<int> { 2, 1 });
		else if (op.name == "blink")
			controller.smartBind(value, vector<int> { 2, 2 });
	} else if (midiBehavior == 3) {
		vector<string> invalids = {
			"smartBind", "ascending", "descending", "blink"
		};
		for (const auto& i : invalids)
			if (op.name == i)
				return;
		controller.addOperation(op.ptr, op.params);
		controller.smartBind(value, vector<int> { 3 });
	} else if (midiBehavior == 4) {
		if (op.name == "smartBindSlot")
			controller.smartBind(value, vector<int> { 4, op.params[0]});
	}
	//cout << "Return code: " << (controller.*op.ptr)(value, op.params) << endl;
}

int main()
{
#ifdef d_route
	int tpage, tchan, tnote, tvalue;
	vector<pair<int, int>> sends = {
		{ 0, 0 },
		{ 0, 1 },
		{ 0, 2 },
		{ 0, 3 },
		{ 0, 3 },
		{ 0, 3 },
		{ 0, 3 }
	};
	for (unsigned int i=0; i!=sends.size(); ++i)
	{
		tchan = sends[i].first;
		tnote = sends[i].second;
		opGroup = groups[{tchan, tnote}];
		tpage = currentGroupPage[opGroup].first;
		tvalue = 0;
		//ControllerPointer
		auto op = mapping[tpage][tchan][tnote];
	
		if (midiBehavior == 1)
		{
			(controller.*op.ptr)(tvalue, op.params);
			//cout << "Return code: " << returnVal << endl;
		} else if (midiBehavior == 2) {
			if (op.name == "smartBind") //exit bind mode
				controller.smartBind(tvalue, vector<int> { 0, 0 });
			else if (op.name == "ascending")
				controller.smartBind(tvalue, vector<int> { 2, 0 });
			else if (op.name == "descending")
				controller.smartBind(tvalue, vector<int> { 2, 1 });
			else if (op.name == "blink")
				controller.smartBind(tvalue, vector<int> { 2, 2 });
		} else if (midiBehavior == 3) {
			vector<string> invalids = {
				"smartBind", "ascending", "descending", "blink"
			};
			for (const auto& i : invalids)
				if (op.name == i)
					return 60;
			controller.addOperation(op.ptr, op.params);
			controller.smartBind(tvalue, vector<int> { 3 });
		} else if (midiBehavior == 4) {
			if (op.name == "smartBindSlot")
				controller.smartBind(tvalue, vector<int> { 4, op.params[0]});
		}
	}
	cin.get();
	return 0;
#endif

	//prevent opening a port if correct controller isn't found
	for (unsigned int i=0; i!=midiin->getPortCount(); ++i)
	{
		if (midiin->getPortName(i) == "APC40 mkII")
		{
			midiin->openPort(i);
			midiin->setCallback(&route);
		}
	}
	for (unsigned int i=0; i!=midiout->getPortCount(); ++i)
	{
		if (midiout->getPortName(i) == "resn8")
		{
			midiout->openPort(i);
		}
	}
	midiout->openVirtualPort("resn8");

	//CLI options will go here

	cout << "\nReading MIDI input .. press <enter> to quit.\n";
	cin.get();

	return 0;
}

/* ERROR CODES:
 * 99: Mapping not found
 * 85: Out of bounds
 * 80: MIDI controller not found
 * 70: Invalid char for send function
 * 60: Invalid smartBind )input
 * 50: Inactive bind activated
 */
