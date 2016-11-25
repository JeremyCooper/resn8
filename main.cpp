//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

/* TODO:
 * Implement rtmidi library
 * Create functional testmodel and testcontroller
 * Model and Controller parent objects need to hold instances of their inherited classes
     |_ models.cpp/controllers.cpp need to implement object choosing function which will	     return a specific subclass based on function input
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
//internal models and interfaces for attached software and user-defined controllers
#include "models.h"
#include "testmodel.h"
#include "controllers.h"
#include "apc80.h"
//Member_Pointer object, midimap structure, and mapping file parser
#include "mapping.cpp"
//implements midi library and routes midi input to relevant pointer
#include "RtMidi.h"

midimap mapping;
const int * page;
int channel, note, value;

void route(double deltatime, vector<unsigned char> * message, void * userData)
{
	//page = &controller.page;
	channel = (int)message->at(0) - 128;
	note = (int)message->at(1);
	value = (int)message->at(2);
	
	/*unsigned int nBytes = message->size();
	for (unsigned int i=0; i!=nBytes; ++i)
		cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
	if (nBytes > 0)
		cout << "stamp = " << deltatime << endl;*/
	cout << "Return code: " << mapping[*page][channel][note](value) << endl;
}

int main()
{
	Test model {}; //Select model with initializer string
	APC80 controller {&model}; //Model is used by controller
	RtMidiIn *midiin = new RtMidiIn();
	mapping = parse_mapping(&controller);

	//prevent opening a port if correct controller isn't found
	for (unsigned int i=0; i!=midiin->getPortCount(); ++i)
		if (midiin->getPortName(i) == "AKAI")
		{
			midiin->openPort(i);
			midiin->setCallback(&route);
			return 80;
		}

	cout << "\nReading MIDI input .. press <enter> to quit.\n";
	cin.get();

	return 0;
}

/* ERROR CODES:
 * 99: Mapping not found
 * 80: MIDI controller not found
 */
