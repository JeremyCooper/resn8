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
	model(drum_identifier + ":R", states["R"]);
	model(drum_identifier + ":G", states["G"]);
	model(drum_identifier + ":B", states["B"]);
	return 0;
}
///////////////////////////
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
}
Controller::Controller (SendMidi * sendmidi, SendDmx * senddmx) :
	model {sendmidi, senddmx}
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
