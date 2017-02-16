#include <iostream>
#include <vector>
#include "RtMidi.h"
using namespace std;

#define list_ports

string drumName1 = "APC40 mkII 24:0";
string drumName2 = "APC40 mkII 20:0";
string drumName3 = "QUNEO 28:0";
int channelGap = 0;
int noteGap = 0;
int triggerChannel = 0;
int triggerNoteStart = 0;

vector<pair<int, int>> control_triggers = {
	{ 144, 20 },
	{ 144, 50 },
	{ 145, 12 }
};

RtMidiIn *drumkit1 = new RtMidiIn();
RtMidiIn *drumkit2 = new RtMidiIn();
RtMidiIn *drumkit3 = new RtMidiIn();
RtMidiOut *midiout = new RtMidiOut();

void route_1(double deltatime, vector<unsigned char> * message, void * userData)
{
	vector<unsigned char> out_message;
	out_message.push_back((int)message->at(0));
	out_message.push_back((int)message->at(1));
	out_message.push_back((int)message->at(2));
	/*for (unsigned int i=0; i!=out_message.size(); ++i)
		out_message[i] += 0;*/
	//cout << out_message[0] << ", " << out_message[1] << ", " << out_message[2] << endl;
	midiout->sendMessage( &out_message );
}
void route_2(double deltatime, vector<unsigned char> * message, void * userData)
{	
	vector<unsigned char> out_message;
	out_message.push_back((int)message->at(0)+channelGap); //channel
	out_message.push_back((int)message->at(1)+noteGap); //note
	out_message.push_back((int)message->at(2));
	for (unsigned int i=0; i!=out_message.size(); ++i)
		out_message[i] += 0;
	midiout->sendMessage( &out_message );
}
void route_3(double deltatime, vector<unsigned char> * message, void * userData)
{	
	int channel = (int)message->at(0);
	int note = (int)message->at(1);
	vector<unsigned char> out_message;
	out_message.push_back(triggerChannel);
	for (unsigned int i=0; i!=control_triggers.size(); ++i)
	{
		if (channel == control_triggers[i].first)
			if (note == control_triggers[i].second)
				out_message.push_back( triggerNoteStart + i );
	}
	out_message.push_back((int)message->at(2));
	for (unsigned int i=0; i!=out_message.size(); ++i)
		out_message[i] += 0;
	midiout->sendMessage( &out_message );
}
int main()
{
#ifdef list_ports
	for (unsigned int i=0; i!=drumkit1->getPortCount(); ++i)
		cout << drumkit1->getPortName(i) << endl;
#endif
	for (unsigned int i=0; i!=drumkit1->getPortCount(); ++i)
		if (drumkit1->getPortName(i) == drumName1)
			drumkit1->openPort(i);
	drumkit1->setCallback( &route_1 );
	for (unsigned int i=0; i!=drumkit2->getPortCount(); ++i)
		if (drumkit2->getPortName(i) == drumName2)
			drumkit2->openPort(i);
	drumkit2->setCallback( &route_2 );
	for (unsigned int i=0; i!=drumkit3->getPortCount(); ++i)
		if (drumkit3->getPortName(i) == drumName3)
			drumkit3->openPort(i);
	drumkit3->setCallback( &route_3 );

	midiout->openVirtualPort("midicompiler");
	cin.get();

	delete drumkit1;
	delete drumkit2;
	delete drumkit3;
	delete midiout;
	return 0;
}
