#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <unistd.h>
#include "drumController.h"
using namespace std;

//#define output_debug
int Controller::drum(int value, vector<int> args)
{
	if (value == 127)
	{
		int kit = args[0];
		if (kit == 0)
		{
			last_hit = Clock::now();
		} else {
			last_hit2 = Clock::now();
		}
		string kit_identifier = "kit_" + to_string(kit);
		string drum = "drum_" + to_string(args[1]);
		string drum_identifier = kit_identifier + ":" + drum;
#ifdef output_debug
		cout << drum_identifier << " has been hit" << endl;
#endif
		model(drum_identifier + ":A", 255);
		int z = rand() % colorschemes[states["mode"]].size();
		model(drum_identifier + ":R", get<0>(colorschemes[states["mode"]][z]));
		model(drum_identifier + ":G", get<1>(colorschemes[states["mode"]][z]));
		model(drum_identifier + ":B", get<2>(colorschemes[states["mode"]][z]));
		model(drum_identifier + ":Y", get<3>(colorschemes[states["mode"]][z]));
		model(drum_identifier + ":W", get<4>(colorschemes[states["mode"]][z]));

		/*if (states["mode"] == 0) {
			model(drum_identifier + ":G", int(states["G"]));
			model(drum_identifier + ":B", int(states["B"]));*/
	/*	} else if (states["mode"] == 1) {
			thread t(&Controller::strobe, this, drum_identifier);
			t.detach();
		} else if (states["mode"] == 2) {
		} else if (states["mode"] == 3) {
		} else if (states["mode"] == 4) {
		} else if (states["mode"] == 5) {
		} else if (states["mode"] == 6) {
		}*/
		resolume(drum_identifier, 127);
		if (kit == 0)
		{
			if (lastDrum != drum_identifier)
			{
				drumOff(lastDrum);
				lastDrum = drum_identifier;
			}
		} else {
			if (lastDrum2 != drum_identifier)
			{
				drumOff(lastDrum2);
				lastDrum2 = drum_identifier;
			}
		}
	}
	return 0;
}
void Controller::drumOff(string drum_identifier)
{
#ifdef output_debug
	cout << drum_identifier << " is turning off" << endl;
#endif
	model(drum_identifier + ":A", 0);
/*	if (states["mode"] == 0) {
	} else if (states["mode"] == 1) {
	} else if (states["mode"] == 2) {
	} else if (states["mode"] == 3) {
	} else if (states["mode"] == 4) {
	} else if (states["mode"] == 5) {
	} else if (states["mode"] == 6) {
	}*/
}
int Controller::mode(int value, vector<int> args)
{
	int mode = args[0];
	if (mode != states["mode"])
	{
		int i = 0;
		//assign colors
		/*for (const auto& x : model.dict)
		{
			string color = x.first;
			color = color.substr(color.length()-2, 2);
			if (color == ":A")
			{
				if (i == colorschemes[mode].size())
					i = 0;
				cout << i << endl;
				//cout << x.first << "    " << color << endl;
				string colorChannel = x.first.substr(0, x.first.length()-2);
				model(colorChannel + ":R", get<0>(colorschemes[mode][i]));
				model(colorChannel + ":G", get<1>(colorschemes[mode][i]));
				model(colorChannel + ":B", get<2>(colorschemes[mode][i]));
				model(colorChannel + ":Y", get<3>(colorschemes[mode][i]));
				model(colorChannel + ":W", get<4>(colorschemes[mode][i]));
				++i;
			}
		}*/
		for (const auto& x : model.dict)
		{
			string color = x.first;
			color = color.substr(color.length()-2, 2);
			if (color == ":A")
			{
				int z = rand() % colorschemes[mode].size();
				//cout << z << endl;
				//cout << x.first << "    " << color << endl;
				string colorChannel = x.first.substr(0, x.first.length()-2);
				model(colorChannel + ":R", get<0>(colorschemes[mode][z]));
				model(colorChannel + ":G", get<1>(colorschemes[mode][z]));
				model(colorChannel + ":B", get<2>(colorschemes[mode][z]));
				model(colorChannel + ":Y", get<3>(colorschemes[mode][z]));
				model(colorChannel + ":W", get<4>(colorschemes[mode][z]));
			}
			states["mode"] = mode;
		}
#ifdef output_debug
		cout << "mode changed to " <<  mode << endl;
#endif
		states["mode"] = mode;
		thread t(&Controller::modeThread, this, mode);
		t.detach();
	}
	return 0;
}
void Controller::modeThread(int mode)
{
#ifdef output_debug
	cout << "mode thread " << mode << " started" << endl;
#endif
/*	if (mode == 0) {
		for (const auto & x : dmx_addresses)
		{
			int alpha = get<3>(x.second);
			int dir = get<4>(x.second);
			if (dir == 0)
			{
				if (alpha == 0)
					dir = 1;
				else
					alpha--;
			} else if (dir == 1) {
				if (alpha == 255)
					dir = 0;
				else
					alpha++;
			}
			model("stage_" + to_string(x.first) + ":A", alpha);
			this_thread::sleep_for(mills(10));
		}
	} else if (mode == 1) {
		for (const auto & x : dmx_addresses)
		{
			model("stage_" + to_string(x.first) + ":A", 255);
			this_thread::sleep_for(mills(100));
			model("stage_" + to_string(x.first) + ":A", 0);
		}
	} else if (mode == 2) {
		for (unsigned int i=0; i!=dmx_addresses.size(); ++i)
		{
			int other = rand() % dmx_addresses.size();
			while ( other == i )
				other = rand() % dmx_addresses.size();
			model("stage_" + to_string(i) + ":A", 255);
			model("stage_" + to_string(other) + ":A", 255);
			this_thread::sleep_for(mills(100));
			model("stage_" + to_string(i) + ":A", 0);
			model("stage_" + to_string(other) + ":A", 0);
		}
	} else if (mode == 3) {
	} else if (mode == 4) {
	} else if (mode == 5) {
	} else if (mode == 6) {
	}
	this_thread::sleep_for(mills(10));*/
}
///////////////////////////
void Controller::strobe(string drum_identifier)
{
	while(lastDrum == drum_identifier)
	{
		model(drum_identifier + ":R", int(states["R"]));
		model(drum_identifier + ":G", int(states["G"]));
		model(drum_identifier + ":B", int(states["B"]));
		this_thread::sleep_for(mills(100));
		model(drum_identifier + ":R", 0);
		model(drum_identifier + ":G", 0);
		model(drum_identifier + ":B", 0);
	}
}
void Controller::clock_thread()
{
	this_thread::sleep_for(mills(200));
	mode(0, vector<int>{states["initialMode"]});
	while (true)
	{
		if (newMode == true)
		{
			modeStart = Clock::now();
			newMode = false;
		}
		if (lastDrum != "")
		{
			mills time_since = chrono::duration_cast<mills>(Clock::now() - last_hit);
			if (time_since > mills(2000))
			{
				drumOff(lastDrum);
				lastDrum = "";
			}
			this_thread::sleep_for(mills(500));
		}
		if (lastDrum2 != "")
		{
			mills time_since = chrono::duration_cast<mills>(Clock::now() - last_hit2);
			if (time_since > mills(2000))
			{
				drumOff(lastDrum2);
				lastDrum2 = "";
			}
			this_thread::sleep_for(mills(500));
		}
		mills mode_time = chrono::duration_cast<mills>(Clock::now() - modeStart);
		if (mode_time > chrono::minutes(3))
		{
			cout << states["mode"] << endl;
			if (states["mode"] == colorschemes.size()-1)
			{
				mode(0, std::vector<int> { 0 });
			} else {
				mode(0, std::vector<int> { states["mode"] + 1 });
			}
			newMode = true;
		}
	}
}
void Controller::setupHooks()
{
	hooks["drum"] = &Controller::drum;
	hooks["mode"] = &Controller::mode;
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
	states["mode"] = 100;
	states["initialMode"] = 0;
	states["primary"] = 0; //0=red, 1=green, 2=blue
	states["R"] = 255;
	states["G"] = 255;
	states["B"] = 0;
	states["A"] = 0; //?
	states["W"] = 0; //?
	newMode = true;
}
void Controller::setupLights()
{
	dmx_addresses = {
		{ 0, { 0, 0, 0 }},
		{ 10, { 0, 0, 0 }},
		{ 20, { 0, 0, 0 }},
		{ 30, { 0, 0, 0 }},
		{ 40, { 0, 0, 0 }},
		{ 50, { 0, 0, 0 }},
		{ 60, { 0, 0, 0 }},
		{ 70, { 0, 0, 0 }},
		{ 80, { 0, 0, 0 }},
		{ 90, { 0, 0, 0 }},
		{ 100, { 0, 0, 0 }},
		{ 110, { 0, 0, 0 }},
		{ 120, { 0, 0, 0 }},
		{ 130, { 0, 0, 0 }},
		{ 140, { 0, 0, 0 }},
		{ 150, { 0, 0, 0 }}
	};
}
void Controller::setupColors()
{
	colorschemes.resize(9);
	colorschemes[0].push_back({ 255, 0, 0, 0, 0 }); //red
	colorschemes[0].push_back({ 0, 0, 0, 255, 0 }); //amber
	colorschemes[0].push_back({ 0, 0, 255, 0, 0 }); //blue
	colorschemes[0].push_back({ 160, 0,	160, 0, 0 }); //pink

	colorschemes[1].push_back({ 0, 0, 255, 0, 0 }); //blue
	colorschemes[1].push_back({ 0, 0, 0, 0, 255 }); //white

	colorschemes[2].push_back({ 0, 0, 255, 0, 0 }); //blue
	colorschemes[2].push_back({ 0, 255, 0, 0, 0 }); //green
	colorschemes[2].push_back({ 0, 0, 0, 255, 0 }); //amber
	colorschemes[2].push_back({ 0, 160, 160, 0, 0 }); //cyan

	//blue amber
	colorschemes[3].push_back({ 0, 0, 255, 0, 0 });
	colorschemes[3].push_back({ 0, 0, 0, 255, 0 });

	//blue pink cyan red
	colorschemes[4].push_back({ 0, 0, 255, 0, 0 });
	colorschemes[4].push_back({ 160, 0, 160, 0, 0 });
	colorschemes[4].push_back({ 0, 160, 160, 0, 0 });
	colorschemes[4].push_back({ 255, 0, 0, 0, 0 });

	//green purple
	colorschemes[5].push_back({ 0, 255, 0, 0, 0 });
	colorschemes[5].push_back({ 160, 0, 255, 0, 0 });

	//red white
	colorschemes[6].push_back({ 255, 0, 0, 0, 0 });
	colorschemes[6].push_back({ 0, 0, 0, 0, 255 });

	//cyan purple amber
	colorschemes[7].push_back({ 160, 0, 160, 0, 0 });
	colorschemes[7].push_back({ 160, 0, 255, 0, 0 });
	colorschemes[7].push_back({ 0, 0, 0, 255, 0 });

	//red blue
	colorschemes[8].push_back({ 255, 0, 0, 0, 0 });
	colorschemes[8].push_back({ 0, 0, 255, 0, 0 });
}
/*Controller::Controller (SendMidi * sendmidi) :
	model {sendmidi}
{
	midiBehavior = 1;
	setupHooks();
	setupStates();
	//setupFeedback();
	lastDrum = "";
}*/
#ifdef dmx_out
Controller::Controller (SendMidi * sendmidi, SendDmx * senddmx) :
	model {senddmx}, resolume {sendmidi}
{
	midiBehavior = 1;
	setupHooks();
	setupStates();
	setupColors();
	setupLights();
	setupFeedback();
	lastDrum = "";
	lastDrum2 = "";
	thread t(&Controller::clock_thread, this);
	t.detach();
	//start mode specific stuff
}
#endif
Controller::Ptr Controller::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
