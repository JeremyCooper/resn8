//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

/* TODO:
 * Implement midiout
 * Hard-coded parameters
 * Create functional testmodel and testcontroller
 * Midi input from attached software (midi input from multiple sources) 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#include "RtMidi.h"
#include "testmodel.cpp"
#include "feedbackClass.cpp"
#include "apc80.cpp"
#include "mapping.cpp"

midimap mapping;
const int * page;
int channel, note, value;

//d_midi, d_route
#define d_route

int sendMidi(Reference _ref, int value)
{
	cout << "Sending midi: " << _ref.channel << ", " << _ref.note << ", " << value << endl;
	return 0;
}

//::::::::::::::::::::::::::
APC80 controller {&sendMidi};
//::::::::::::::::::::::::::

void route(double deltatime, vector<unsigned char> * message, void * userData)
{
	page = &controller.page;
	channel = (int)message->at(0) - 128;
	note = (int)message->at(1);
	value = (int)message->at(2);
	
#ifdef d_midi
	unsigned int nBytes = message->size();
	for (unsigned int i=0; i!=nBytes; ++i)
		cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
	if (nBytes > 0)
		cout << "stamp = " << deltatime << endl;
#endif
	auto apcptr = mapping[*page][channel][note];
	cout << "Return code: " << (controller.*apcptr)(value, vector<int> { 1 }) << endl;
}

int main()
{
	RtMidiIn *midiin = new RtMidiIn();
	mapping = parse_mapping(&controller);

#ifdef d_route
	int tpage, tchan, tnote, tvalue;
	tpage = 0;
	tchan = 0;
	tnote = 0;
	tvalue = 0;

	//APC80::ApcPtr
	auto apcptr = mapping[tpage][tchan][tnote];
	//call pointer with tvalue as value and vector<int> param list. Cout the return code. 
	cout << "Return code: " << (controller.*apcptr)(tvalue, vector<int> { 1 }) << endl;
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
 * 80: MIDI controller not found
 */
