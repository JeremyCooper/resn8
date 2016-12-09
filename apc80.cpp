//apc80.cpp
#include <iostream>
#include <vector>
#include "apc80.h"
using namespace std;
void APC80::fillHooks()
{
	hooks["ignoreMidi"] = &APC80::ignoreMidi;
	hooks["resetLayer"] = &APC80::resetLayer;
	hooks["changeLayer"] = &APC80::changeLayer;
	hooks["changeBackgroundLayer"] = &APC80::changeBackgroundLayer;
	hooks["changeGroupPage"] = &APC80::changeGroupPage;
	hooks["red"] = &APC80::red;
	hooks["green"] = &APC80::green;
	hooks["blue"] = &APC80::blue;
	hooks["red_bg"] = &APC80::red_bg;
	hooks["green_bg"] = &APC80::green_bg;
	hooks["blue_bg"] = &APC80::blue_bg;
	hooks["changeCurrentSCP"] = &APC80::changeCurrentSCP; // SCP = Saved Clip Page
}
//////////////////////////////////////////
//need to update feedback for affected controls when switching group pages
int APC80::changeGroupPage(int value, vector<int> args)
{
	int targetGroup = args[0];
	int currentPage = currentGroupPage[targetGroup].first;
	int newPage = currentPage;
	if (args[1] == 0)
	{
		int lastPage = currentGroupPage[targetGroup].second;
		int direction = args[2];
		if (direction == -1)
		{
			if (currentPage == 0)
			{
				newPage = lastPage-1;
			} else {
				newPage = currentPage-1;
			}
		} else if (direction == 1)
		{
			if (currentPage == lastPage)
			{
				newPage = 0;
			} else {
				newPage = currentPage+1;
			}
		}
	} else {
		newPage = args[1];
	}
	currentGroupPage[targetGroup].first = newPage;
	//get list of all members in group.
	cout << targetGroup << ", " << newPage << endl;
	updateFeedback(group_members[targetGroup], pageDisplayValues[newPage]);
	return 0;
}
int APC80::ignoreMidi(int value, vector<int> args)
{
	if (args[0] == 1)
		states["ignoreMidi"] = 1;
	else
		states["ignoreMidi"] = 0;
	return 0;
}
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
int APC80::changeLayer(int value, vector<int> args = {})
{
	int layer = args[0];
	string ls = to_string(layer);
	states["currentLayer"] = layer;
	vector<string> elements = {
		"r", "g", "b"
	};
	updateFeedback(elements, ls);
	return 0;
}
int APC80::changeBackgroundLayer(int value, vector<int> args)
{
	int layer = args[0];
	string ls = to_string(layer);
	states["backgroundLayer"] = layer;
	vector<string> elements = {
		"r_bg", "g_bg", "b_bg"
	};
	updateFeedback(elements, ls);
	return 0;
}
int APC80::resetLayer(int value, vector<int> args)
{
	//condense these returns and return based on that	
	send("r", 0);
	send("g", 0);
	send("b", 0);
	return 0;
}
int APC80::red(int value, vector<int> args)
{
	return send("r", value);
}
int APC80::green(int value, vector<int> args)
{
	return send("g", value);
}
int APC80::blue(int value, vector<int> args)
{
	return send("b", value);
}
int APC80::red_bg(int value, vector<int> args)
{
	return send("r_bg", value);
}
int APC80::green_bg(int value, vector<int> args)
{
	return send("g_bg", value);
}
int APC80::blue_bg(int value, vector<int> args)
{
	return send("b_bg", value);
}
//////////////////////////////////////////
void APC80::setupFeedback()
{
	//anything dynamic needed?
	//savedClipViewStruct scvs {};
	//feedback.savedClipView(scvs);
	for (auto const& i : model.dict)
	{
		model(i.first, i.second.value);
	}
	for (auto const& i : feedback.dict)
	{
		feedback(i.first, i.second.value);
	}
}
void APC80::updateFeedback(vector<string> elements, map<string, int>& values)
{
	for (auto const& i : elements)
	{
		feedback(i, values[i]);
	}
}
//updateFeedback(group_members[targetGroup], pageDisplayValues[newPage]);
void APC80::updateFeedback(vector<string>& elements, string layer)
{
	for (auto const& i : elements)
	{
		string elementIt = i;
		string postfix = "";
		if (i.length() > 3)
		{
			postfix = i.substr(i.length()-3, 3);
			if (postfix == "_bg")
				elementIt = i.substr(0, i.length()-3);
		}
		string inputIt = elementIt+layer;
		int value = model.dict[inputIt].value;
		feedback(elementIt+postfix, value);
	}
}
void APC80::setupStates()
{
	states["ignoreMidi"] = 0;
	states["currentSCP"] = 0;
	states["numberSCP"] = 3;
	states["currentLayer"] = 0;
	states["backgroundLayer"] = 1;
}
void APC80::setupGroups()
{
	vector<string> grp0 = {
		"0x0", "0x1", "0x2", "1x0", "1x1", "1x2"
	};
	group_members.push_back(grp0);
	vector<string> grp1 = {
		"1x0", "1x1", "1x2"
	};
	group_members.push_back(grp1);
}
void APC80::setupPageDisplayValues()
{
	map<string, int> pg0 = {
		{"0x0", 120}, {"0x1", 120}, {"0x2", 120},
		{"1x0", 120}, {"1x1", 120}, {"1x2", 120}
	};
	pageDisplayValues.push_back(pg0);
	map<string, int> pg1 = {
		{"0x0", 30}, {"0x1", 30}, {"0x2", 30},
		{"1x0", 30}, {"1x1", 30}, {"1x2", 30}
	};
	pageDisplayValues.push_back(pg1);
}
//map<string, map<string, int>>
int APC80::send(string element, int value)
{
	string elementId, postfix, layer;
	if (element.length() > 3)
	{
		postfix = element.substr(element.length()-3, 3);
		if (postfix == "_bg")
		{
			elementId = element.substr(0, element.length()-3);
			layer = to_string(states["backgroundLayer"]);
			model(elementId+layer, value);
			feedback(elementId+"_bg", value);
		} else {
			layer = to_string(states["currentLayer"]);
			model(element+layer, value);
			feedback(element, value);
		}
	} else {
		layer = to_string(states["currentLayer"]);
		model(element+layer, value);
		feedback(element, value);
	}
	return 0;
}
APC80::APC80(int (*sendMidi) (Reference, int)) :
	sendMidi(sendMidi), model {sendMidi}, feedback {sendMidi}
{
	fillHooks();//setupHooks()
	setupStates();
	setupGroups();
	setupPageDisplayValues();
	//setupFeedback();
}
APC80::Ptr APC80::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
