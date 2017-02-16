//Virtual Midi Controller
//By: Jeremy Cooper

/* TODO:
 * Redo binders to store data in "Bind" objects
 * BPM manager
 * Copy actions upon bind, freeing origin bind
 * Clear smartBind, exStack functionality
 * exStack can hold smartBinds.
 * Timeout for binding modes?
 * Absolute(layer) bindings?
 * DMX out
 */

//d_midi, d_route, d_parser
//FIXME TODO FIXME TODO FIXME TODO
//#define d_midi
//#define d_route
//#define dmx_out
//#define output_mapper
//#define binder_on
//FIXME TODO FIXME TODO FIXME TODO

#include <iostream>
#include <vector>
#include <map>
#include "RtMidi.h"
#ifdef dmx_out
#include <ola/DmxBuffer.h>
#include <ola/client/StreamingClient.h>
#endif
using namespace std;

string midiInName = "RtMidi Output Client 131:0";
string midiOutName = "CH345 20:0";

struct Reference
{
	Reference() {}
	Reference(int channel, int note) :
		channel(channel), note(note) { value = 0; }
	Reference(int channel, int note, int value) :
		channel(channel), note(note), value(value) {}
	unsigned char channel, note, value;
};
#ifdef dmx_out
class SendDmx
{
public:
	SendDmx(ola::client::StreamingClient * ola_client)
		: ola_client(ola_client) { buffer.Blackout(); ola_client->Setup(); }
	void send(Reference _ref, int value)
	{
		buffer.SetChannel(_ref.note, value);
		ola_client->SendDmx(_ref.channel, buffer);
	}
private:
	ola::client::StreamingClient * ola_client;
	ola::DmxBuffer buffer;
};
#endif
class SendMidi
{
public:
	SendMidi(RtMidiOut * midiout) : midiout(midiout) {}
	void send(Reference _ref, int value)
	{
		vector<unsigned char> out_message;
		out_message.push_back(_ref.channel);
		out_message.push_back(_ref.note);
		out_message.push_back(value);
		for (unsigned int i=0; i!=out_message.size(); ++i)
			out_message[i] += 0;
		cout << "Sending midi: " << int(out_message[0]) << ", " << int(out_message[1]) << ", " << int(out_message[2]) << endl;
	//	for (int i=0; i<29; i++)
			midiout->sendMessage( &out_message );
	}
private:
	RtMidiOut * midiout;
};
int midiBehavior;
vector<pair<int,int>> currentGroupPage(10); //current page, last page
map<pair<int, int>, int> groups;
//#include "Controllers/apc80.cpp"
#include "Controllers/drumController.cpp"
//:::::::::::::::::::::::::::
//typedef APC80 Controller;
typedef Controller Controller;
//:::::::::::::::::::::::::::
#include "mapping.cpp"

int channel, note, opGroup, page, value;

RtMidiIn *midiin = new RtMidiIn();
RtMidiOut *midiout = new RtMidiOut();
#ifdef dmx_out
ola::client::StreamingClient ola_client(
	(ola::client::StreamingClient::Options()));
SendDmx senddmx {&ola_client};
#endif
SendMidi sendmidi {midiout};
#ifdef dmx_out
Controller controller {&sendmidi, &senddmx};
#else
Controller controller {&sendmidi};
#endif
midimap mapping = parse_mapping(&controller);

void route(double deltatime, vector<unsigned char> * message, void * userData)
{
	channel = (int)message->at(0);// - 128;
	note = (int)message->at(1);
	opGroup = groups[ {channel, note} ];
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
	}
#ifdef binder_on
	  /*else if (midiBehavior == 2) {
		int returnValue = (controller.*op.ptr)(value, op.params);
		if (returnValue != 0) { cout << "Error: " << returnValue << endl; return; }*/
	 else if (midiBehavior == 2) {
		//grab control element
		vector<string> invalids = {
			"ascending", "descending", "blink",
			"min", "mid", "max"
		};
		for (const auto& i : invalids)
			if (op.name == i)
				return;
		//exit binder
		if (op.name == "smartBind")
			controller.smartBind(value, vector<int> { 4 });
		else if (op.name == "exStack")
			controller.exStack(value, vector<int> { 4 });

		controller.addOperation(op.ptr, op.params);
		if (controller.bindMode == "smartBind")
			controller.smartBind(value, vector<int> { 2 });
		else if (controller.bindMode == "exStack")
			controller.exStack(value, vector<int> { 2 });
	} else if (midiBehavior == 3) {
		//grab bind parameter
		if (op.name == "smartBind")
			controller.smartBind(value, vector<int> { 4 }); //exit smartBind
		else if (op.name == "exStack")
			controller.exStack(value, vector<int> { 4 }); //exit exStack
		else if (op.name == "ascending")
			controller.smartBind(value, vector<int> { 3, 0 });
		else if (op.name == "descending")
			controller.smartBind(value, vector<int> { 3, 1 });
		else if (op.name == "blink")
			controller.smartBind(value, vector<int> { 3, 2 });
		else if (op.name == "min")
			controller.exStack(value, vector<int> { 3, 0 });
		else if (op.name == "mid")
			controller.exStack(value, vector<int> { 3, 64 });
		else if (op.name == "max")
			controller.exStack(value, vector<int> { 3, 127 });
	} else if (midiBehavior == 4) {
		if (op.name == "smartBindSlot")
			controller.smartBind(value, vector<int> { 4, op.params[0]});
	}
#endif
	//cout << "Return code: " << (controller.*op.ptr)(value, op.params) << endl;
}

int main()
{
	for (unsigned int i=0; i!=midiout->getPortCount(); ++i)
		if (midiout->getPortName(i) == midiOutName)
			//cout << "hi" << endl;
			midiout->openPort(i);
	//midiout->openVirtualPort("resn8");
#ifdef d_route
	int tpage, tchan, tnote, tvalue;
	vector<pair<int, int>> sends = {
		{ 0, 0 },
		{ 0, 1 },
		{ 1, 0 },
		{ 1, 1 }
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
			int returnValue = (controller.*op.ptr)(tvalue, op.params);
			if (returnValue != 0) { return returnValue; }
			//cout << "Return code: " << returnVal << endl;
		}
#ifdef binder_on
		  else if (midiBehavior == 2) {
			vector<string> invalids = {
				"ascending", "descending", "blink",
				"min", "mid", "max"
			};
			for (const auto& i : invalids)
				if (op.name == i)
					return 60;
			//exit binder
			if (op.name == "smartBind")
				controller.smartBind(tvalue, vector<int> { 4 });
			else if (op.name == "exStack")
				controller.exStack(tvalue, vector<int> { 4 });

			controller.addOperation(op.ptr, op.params);
			if (controller.bindMode == "smartBind")
				controller.smartBind(tvalue, vector<int> { 2 });
			else if (controller.bindMode == "exStack")
				controller.exStack(tvalue, vector<int> { 2 });
		} else if (midiBehavior == 3) {
			if (op.name == "smartBind") //exit bind mode
				controller.smartBind(tvalue, vector<int> { 0, 0 }); //midibehavior, param
			else if (op.name == "ascending")
				controller.smartBind(tvalue, vector<int> { 3, 0 });
			else if (op.name == "descending")
				controller.smartBind(tvalue, vector<int> { 3, 1 });
			else if (op.name == "blink")
				controller.smartBind(tvalue, vector<int> { 3, 2 });
			else if (op.name == "min")
				controller.exStack(tvalue, vector<int> { 3, 0 });
			else if (op.name == "mid")
				controller.exStack(tvalue, vector<int> { 3, 64 });
			else if (op.name == "max")
				controller.exStack(tvalue, vector<int> { 3, 127 });
		} else if (midiBehavior == 4) {
			if (op.name == "smartBindSlot")
				controller.smartBind(tvalue, vector<int> { 4, op.params[0]});
			else if (op.name == "exStack")
				controller.exStack(tvalue, vector<int> { 4, op.params[0]});
		}
#endif
	}
	//cin.get(); //uncomment to keep alive for threads
	return 0;
#endif

	//prevent opening a port if correct controller isn't found

	for (unsigned int i=0; i!=midiin->getPortCount(); ++i)
	{
		cout << midiin->getPortName(i) << endl;
		if (midiin->getPortName(i) == midiInName)
		{
			midiin->openPort(i);
			midiin->setCallback(&route);
		}
	}

#ifdef output_mapper
	controller.output_map();
#endif

	//CLI options will go here

	cout << "\nReading MIDI input .. press <enter> to quit.\n";
	cin.get();

	delete midiin;
	delete midiout;
	return 0;
}

/* ERROR CODES:
 * 99: Mapping not found
 * 85: Out of bounds
 * 80: MIDI controller not found
 * 70: Invalid char for send function
 * 60: Invalid smartBind )input
 * 50: Inactive bind activated
 * 40: Invalid playback control
 */
