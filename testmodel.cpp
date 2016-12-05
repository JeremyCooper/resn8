//testmodel.cpp
#include "testmodel.h"
using namespace std;
void Test::fillDictionary()
{
	dict["r"] = { 144, 0 };
	dict["g"] = { 144, 1 };
	dict["b"] = { 144, 2 };
}
Test::Test(int (*sendMidi) (Reference, int)) : sendMidi(sendMidi)
{
	fillDictionary();
}
int Test::operator()(string element, int value)
{
	return sendMidi(dict[element], value);
}
