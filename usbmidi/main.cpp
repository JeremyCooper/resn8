//usbmidi
#include <iostream>
#include <vector>
#include "RtMidi.h"
using namespace std;

//string MidiInName = "APC40 mkII 24:0";
string MidiInName = "RtMidi Output Client 133:0";

RtMidiIn *midiin = new RtMidiIn();
RtMidiOut *midiout = new RtMidiOut();
void route(double deltatime, vector<unsigned char> * message, void * userData)
{
	cout << "sending message" << endl;
	vector<unsigned char> out_message;
	out_message.push_back((int)message->at(0));
	out_message.push_back((int)message->at(1));
	out_message.push_back((int)message->at(2));
	for (unsigned int i=0; i!=out_message.size(); ++i)
		out_message[i] += 0;
	midiout->sendMessage( &out_message );
}
int main()
{
	for (unsigned int i=0; i!=midiin->getPortCount(); ++i)
		cout << midiin->getPortName(i) << endl;
	for (unsigned int i=0; i!=midiin->getPortCount(); ++i)
		if (midiin->getPortName(i) == MidiInName)
			midiin->openPort(i);
	midiin->setCallback( &route );

	for (unsigned int i=0; i!=midiout->getPortCount(); ++i)
		if (midiout->getPortName(i) == "CH345 20:0")
			midiout->openPort(i);

	cin.get();
	delete midiin;
	delete midiout;
	return 0;
}
