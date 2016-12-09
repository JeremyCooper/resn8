//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

/* TODO:
 * Implement midiout
 * Create seperate header file(s) containing utilities
 * Use typedef to declare controller
     -change controller object in one spot and done
 * Create functional testmodel and testcontroller
 * Midi input from attached software (midi input from multiple sources) 
 */

//d_midi, d_route, d_parser
//apc80, james
//FIXME TODO FIXME TODO FIXME TODO
#define d_route
#define jeremy
//FIXME TODO FIXME TODO FIXME TODO

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include "RtMidi.h"
#include "testmodel.cpp"
#include "feedbackClass.cpp"
vector<pair<int,int>> currentGroupPage(10); //current page, last page
map<pair<int, int>, int> groups;
#include "apc80.cpp"

#include "mapping.cpp"

midimap mapping;
int channel, note, opGroup, page, value;

int sendMidi(Reference _ref, int value)
{
	cout << "Sending midi: " << _ref.channel << ", " << _ref.note << ", " << value << endl;
	return 0;
}

//:::::::::::::::::::::::::::
#ifdef jeremy
APC80 controller {&sendMidi};
#endif
#ifdef james
//james controller here
#endif
//:::::::::::::::::::::::::::

void route(double deltatime, vector<unsigned char> * message, void * userData)
{
	channel = (int)message->at(0) - 128;
	note = (int)message->at(1);
	opGroup = groups[{channel, note}];
	page = currentGroupPage[opGroup].first;
	value = (int)message->at(2);
	
#ifdef d_midi
	unsigned int nBytes = message->size();
	for (unsigned int i=0; i!=nBytes; ++i)
		cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
	if (nBytes > 0)
		cout << "stamp = " << deltatime << endl;
#endif
	auto op = mapping[page][channel][note];
	cout << "Return code: " << (controller.*op.ptr)(value, op.params) << endl;
}

int main()
{
	RtMidiIn *midiin = new RtMidiIn();
	mapping = parse_mapping(&controller);

#ifdef d_route
	int tpage, tchan, tnote, tvalue;
	tchan = 0;
	tnote = 0;
	opGroup = groups[{channel, note}];
	tpage = currentGroupPage[opGroup].first;
	tvalue = 0;

	if (controller.states["ignoreMidi"] == 0)
	{
		auto op = mapping[tpage][tchan][tnote];
		int returnVal = (controller.*op.ptr)(tvalue, op.params);
		cout << "Return code: " << returnVal << endl;
		return returnVal;
	}
	return 0;
#endif

	//prevent opening a port if correct controller isn't found
	for (unsigned int i=0; i!=midiin->getPortCount(); ++i)
		if (midiin->getPortName(i) == "APC40 mkII")
		{
			midiin->openPort(i);
			midiin->setCallback(&route);
			return 80;
		}

	//CLI options will go here

	cout << "\nReading MIDI input .. press <enter> to quit.\n";
	cin.get();

	return 0;
}

/* ERROR CODES:
 * 99: Mapping not found
 * 85: Out of bounds
 * 80: MIDI controller not found
 * 70: Invalid char for send function */
