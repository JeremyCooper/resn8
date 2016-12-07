//feedbackClass.cpp
#include "feedbackClass.h"
using namespace std;
void Feedback::fillDictionary()
{
	dict["r0"] = { 150, 0, 50 };
	dict["g0"] = { 150, 1, 50 };
	dict["b0"] = { 150, 2, 50 };
	dict["r1"] = { 151, 0, 50 };
	dict["g1"] = { 151, 1, 50 };
	dict["b1"] = { 151, 2, 50 };
}
int Feedback::savedClipView(savedClipViewStruct scvs)
{
	return 0;
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
