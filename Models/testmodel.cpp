//testmodel.cpp
#include "testmodel.h"
using namespace std;
void Test::fillDictionary()
{
	dict["r0"] = { 176, 0, 50 };
	dict["g0"] = { 176, 1, 50 };
	dict["b0"] = { 176, 2, 50 };
	dict["r1"] = { 176, 0, 150 };
	dict["g1"] = { 145, 1, 150 };
	dict["b1"] = { 145, 2, 150 };
	dict["r2"] = { 146, 0, 300 };
	dict["g2"] = { 146, 1, 300 };
	dict["b2"] = { 146, 2, 300 };
	dict["selectLayer0"] = { 144, 0, 0 };
	dict["selectLayer1"] = { 144, 9, 0 };
	dict["selectLayer2"] = { 144, 19, 0 };
	dict["speed0"] = { 176, 0, 0 };
	dict["speed1"] = { 176, 9, 0 };
	dict["speed2"] = { 176, 19, 0 };
	dict["opacity0"] = { 176, 1, 0 };
	dict["opacity1"] = { 176, 10, 0};
	dict["opacity2"] = { 176, 20, 0 };
	dict["reverse0"] = { 144, 1, 0 };
	dict["reverse1"] = { 144, 10, 0 };
	dict["reverse2"] = { 144, 20, 0 };
	dict["forward0"] = { 144, 2, 0 };
	dict["forward1"] = { 144, 11, 0 };
	dict["forward2"] = { 144, 21, 0 };
	dict["random0"] = { 144, 3, 0 };
	dict["random1"] = { 144, 12, 0 };
	dict["random2"] = { 144, 22, 0 };
}
Test::Test(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	fillDictionary();
}
int Test::operator()(string element, int value)
{
	dict[element].value = value;
	sendmidi->send(dict[element], value);
	//cout << dict[element].channel << ", " << dict[element].note << ", " << value << endl;
	return 0;
}
