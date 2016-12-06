//testmodel.cpp
#include "testmodel.h"
using namespace std;
void Test::fillDictionary()
{
	dict["r0"] = { 144, 0, 50 };
	dict["g0"] = { 144, 1, 50 };
	dict["b0"] = { 144, 2, 50 };
	dict["r1"] = { 145, 0, 50 };
	dict["g1"] = { 145, 1, 50 };
	dict["b1"] = { 145, 2, 50 };
}
Test::Test(int (*sendMidi) (Reference, int)) : sendMidi(sendMidi)
{
	fillDictionary();
}
int Test::operator()(string element, int value)
{
	return sendMidi(dict[element], value);
}
