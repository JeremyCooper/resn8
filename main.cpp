//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

/* TODO:
 * Implement midiout
 * Create functional testmodel and testcontroller
 * Model and Controller parent objects need to hold instances of their inherited classes
     |_ models.cpp/controllers.cpp need to implement object choosing function which will
		return a specific subclass based on function input
	 |_ Models object should be able to store multiple objects so that controllers can
	    interface with multiple models at once
 * Midi input from attached software (midi input from multiple sources) 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#include "models.h"
#include "testmodel.h"
#include "controllers.h"
#include "apc80.h"
#include "mapping.cpp"
#include "RtMidi.h"

midimap mapping;
const int * page;
int channel, note, value;

//d_midi, d_route
#define d_route

void route(double deltatime, vector<unsigned char> * message, void * userData)
{
	//page = &controller.page;
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
	//cout << "Return code: " << mapping[*page][channel][note](value) << endl;
}

/*void sendMidi(int channel, int note, int value)
{
	cout << channel << ", " << note << ", " << value << endl;
}*/	
void sendMidi(Reference _ref, int value)
{
	cout << _ref.channel << ", " << _ref.note << endl;
}

int main()
{
	Test model {&sendMidi}; //Give model ability to send midi
	APC80 controller {&model}; //Model is used by controller
	RtMidiIn *midiin = new RtMidiIn();
	mapping = parse_mapping(&controller);

	//model.master(5, vector<int> {1});
#ifdef d_route
	int tpage, tchan, tnote, tvalue;
	tpage = 0;
	tchan = 0;
	tnote = 0;
	tvalue = 0;
	//return controller.master(1, vector<int> {1});
	Test::TestPtr testptr;
	APC80::ApcPtr apcptr;
	char obj = mapping[tpage][tchan][tnote](testptr, apcptr);
	if (obj == 'M')
		cout << "Return code: " << (model.*testptr)(1, vector<int> {1}) << endl;
	else if (obj == 'C')
		cout << "Return code: " << (controller.*apcptr)(1, vector<int> {1}) << endl;
	return 0;
	//(model.*testpointer)(1, vector<int> {1});
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
