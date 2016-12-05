//feedback.cpp
#include "feedbackClass.h"
using namespace std;
void Feedback::fillDictionary()
{
	dict["r"] = { 150, 0 };
	dict["g"] = { 150, 1 };
	dict["b"] = { 150, 2 };
}
Feedback::Feedback(int (*sendMidi) (Reference, int)) : sendMidi(sendMidi)
{
	fillDictionary();
}
int Feedback::operator()(string element, int value)
{
	return sendMidi(dict[element], value);
}
