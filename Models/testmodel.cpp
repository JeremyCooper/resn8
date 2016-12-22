//testmodel.cpp
#include "testmodel.h"
using namespace std;
void Test::fillDictionary()
{
	dict["r0"] = { 144, 0, 50 };
	dict["g0"] = { 144, 1, 50 };
	dict["b0"] = { 144, 2, 50 };
	dict["r1"] = { 145, 0, 150 };
	dict["g1"] = { 145, 1, 150 };
	dict["b1"] = { 145, 2, 150 };
	dict["r2"] = { 146, 0, 300 };
	dict["g2"] = { 146, 1, 300 };
	dict["b2"] = { 146, 2, 300 };
}
Test::Test(int (*sendMidi) (Reference, int)) : sendMidi(sendMidi)
{
	fillDictionary();
}
int Test::operator()(string element, int value)
{
	dict[element].value = value;
	return sendMidi(dict[element], value);
}
