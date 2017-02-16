#include <iostream>
#include <vector>
#include <chrono>
#include <unistd.h>
#include "drumController.h"
using namespace std;
int Controller::drum(int value, vector<int> args)
{
	string kit = "kit_" + to_string(args[0]);
	string drum = "drum_" + to_string(args[1]);
	string drum_identifier = kit + ":" + drum;
	if (states["mode"] == 0) {
		model(drum_identifier + ":R", int(states["R"] * (value/127.0)));
		model(drum_identifier + ":G", int(states["G"] * (value/127.0)));
		model(drum_identifier + ":B", int(states["B"] * (value/127.0)));
	} else if (states["mode"] == 1) {
	} else if (states["mode"] == 2) {
	} else if (states["mode"] == 3) {
	} else if (states["mode"] == 4) {
	} else if (states["mode"] == 5) {
	} else if (states["mode"] == 6) {
	}
	drumOff(lastDrum);
	lastDrum = drum_identifier;
	return 0;
}
int Controller::mode(int value, vector<int> args)
{
	states["mode"] = args[0];
	return 0;
}
///////////////////////////
void Controller::drumOff(string drum_identifier)
{
	if (states["mode"] == 0) {
		model(drum_identifier + ":R", 0);
		model(drum_identifier + ":G", 0);
		model(drum_identifier + ":B", 0);
	} else if (states["mode"] == 1) {
	} else if (states["mode"] == 2) {
	} else if (states["mode"] == 3) {
	} else if (states["mode"] == 4) {
	} else if (states["mode"] == 5) {
	} else if (states["mode"] == 6) {
	}
}
void Controller::setupHooks()
{
	hooks["drum"] = &Controller::drum;
}
void Controller::setupFeedback()
{
	for (auto const& i : model.dict)
	{
		model(i.first, i.second.value);
	}
}
void Controller::setupStates()
{
	states["mode"] = 0;
	states["R"] = 255;
	states["G"] = 0;
	states["B"] = 0;
	states["A"] = 0; //?
	states["W"] = 0; //?
}
Controller::Controller (SendMidi * sendmidi) :
	model {sendmidi}
{
	midiBehavior = 1;
	setupHooks();
	setupStates();
	//setupFeedback();
	lastDrum = "";
}
Controller::Controller (SendMidi * sendmidi, SendDmx * senddmx) :
	model {sendmidi, senddmx}//, resolume {sendmidi}
{
	midiBehavior = 1;
	setupHooks();
	setupStates();
	//setupFeedback();
}
Controller::Ptr Controller::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
