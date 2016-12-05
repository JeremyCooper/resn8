//apc80.cpp
#include <iostream>
#include <vector>
#include "apc80.h"
using namespace std;
void APC80::fillHooks()
{
	hooks["resetLayer"] = &APC80::resetLayer;
	hooks["abstractfunction"] = &APC80::abstractfunction;
}
void APC80::fillDictionary()
{
//	dict["abstractfunction"] = { 144, 70 };
}
//////////////////////////////////////////
int APC80::resetLayer(int value, vector<int> args)
{
	//condense these returns and return based on that
	send("r", 0);
	send("g", 0);
	send("b", 0);
	return 0;
}
int APC80::abstractfunction(int value, vector<int> args)
{
	return sendMidi(dict["abstractfunction"], value);
}
//////////////////////////////////////////
int APC80::send(string element, int value)
{
	model(element, value);
	feedback(element, value);
	return 0;
}
APC80::APC80(int (*sendMidi) (Reference, int)) :
	sendMidi(sendMidi), model {sendMidi}, feedback {sendMidi}
{
	page = 1;
	fillHooks();
	fillDictionary();
}
APC80::Ptr APC80::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
