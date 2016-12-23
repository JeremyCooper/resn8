//feedbackClass.cpp
#include "feedbackClass.h"
using namespace std;
void Feedback::fillDictionary()
{
	dict["r"] = { 150, 0, 50 };
	dict["g"] = { 150, 1, 50 };
	dict["b"] = { 150, 2, 50 };
	dict["r_bg"] = { 151, 0, 50 };
	dict["g_bg"] = { 151, 1, 50 };
	dict["b_bg"] = { 151, 2, 50 };
	dict["0x0"] = { 0, 0, 300 };
	dict["0x1"] = { 0, 1, 300 };
	dict["0x2"] = { 0, 2, 300 };
	dict["1x0"] = { 1, 0, 300 };
	dict["1x1"] = { 1, 1, 300 };
	dict["1x2"] = { 1, 2, 300 };
}
Feedback::Feedback(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	fillDictionary();
}
int Feedback::operator()(string element, int value)
{
	dict[element].value = value;
	sendmidi->send(dict[element], value);
	return 0;
}
