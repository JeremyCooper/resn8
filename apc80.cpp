//apc80.cpp
#include <iostream>
#include <vector>
#include "apc80.h"
using namespace std;
void APC80::fillHooks()
{
	hooks["resetLayer"] = &APC80::resetLayer;
	hooks["changeLayer"] = &APC80::changeLayer;
	hooks["changeBackgroundLayer"] = &APC80::changeBackgroundLayer;
	hooks["red"] = &APC80::red;
	hooks["green"] = &APC80::green;
	hooks["red_bg"] = &APC80::red_bg;
	hooks["changeCurrentSCP"] = &APC80::changeCurrentSCP; // SCP = Saved Clip Page
}
//////////////////////////////////////////
int APC80::changeCurrentSCP(int value, vector<int> args)
{
	int page = args[0];
	if ((page > states["numberSCP"]) || (page < 0))
	{
		cout << "Invalid page number!" << endl;
		return 89;
	}
	cout << "Switching to saved clip page " << page << endl;
	states["currentSCP"] = page;
	return 0;
}
int APC80::changeLayer(int value, vector<int> args)
{
	int layer = args[0];
	states["currentLayer"] = layer;
	return 0;
}
int APC80::changeBackgroundLayer(int value, vector<int> args)
{
	int layer = args[0];
	states["backgroundLayer"] = layer;
	return 0;
}
int APC80::resetLayer(int value, vector<int> args)
{
	//condense these returns and return based on that	
	string layer = to_string(states["currentLayer"]);
	send("r"+layer, 0);
	send("g"+layer, 0);
	send("b"+layer, 0);
	return 0;
}
int APC80::red(int value, vector<int> args)
{
	string layer = to_string(states["currentLayer"]);
	send("r"+layer, value);
	return 0;
}
int APC80::green(int value, vector<int> args)
{
	return 0;
}
int APC80::red_bg(int value, vector<int> args)
{
	string layer = to_string(states["backgroundLayer"]);
	send("r"+layer, value);
	return 0;
}
//////////////////////////////////////////
void APC80::setupFeedback()
{
	//anything dynamic needed?
	//savedClipViewStruct scvs {};
	//feedback.savedClipView(scvs);
	for (auto const& i : model.dict)
	{
		send(i.first, i.second.value);
	}
	for (auto const& i : feedback.dict)
	{
		send(i.first, i.second.value);
	}
}
void APC80::updateFeedback(vector<string> elements)
{
	for (auto i=elements.begin(); i!=elements.end(); ++i)
		feedback(*i, feedback.dict[*i].value); 
}
void APC80::setupStates()
{
	page = 1;
	states["currentSCP"] = 0;
	states["numberSCP"] = 3;
	states["currentLayer"] = 0;
	states["backgroundLayer"] = 1;
}
int APC80::send(string element, int value)
{
	model(element, value);
	feedback(element, value);
	return 0;
}
APC80::APC80(int (*sendMidi) (Reference, int)) :
	sendMidi(sendMidi), model {sendMidi}, feedback {sendMidi}
{
	fillHooks();
	setupStates();
	//setupFeedback();
}
APC80::Ptr APC80::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
