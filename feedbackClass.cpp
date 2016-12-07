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
}
Feedback::Feedback(int (*sendMidi) (Reference, int)) : sendMidi(sendMidi)
{
	fillDictionary();
}
int Feedback::operator()(string element, int value)
{
	dict[element].value = value;
	return sendMidi(dict[element], value);
}
