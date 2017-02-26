//resModel.cpp
using namespace std;
class Resolume
{
public:
	Resolume(SendMidi *);
	void setupDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
	SendMidi * sendmidi;
};
////////////////////////
void Resolume::setupDictionary()
{
	dict["kit_0:drum_0"] = { 144, 0 };
	dict["kit_0:drum_1"] = { 144, 1 };
	dict["kit_0:drum_2"] = { 144, 2 };
	dict["kit_0:drum_3"] = { 144, 3 };
	dict["kit_0:drum_4"] = { 144, 4 };
	dict["kit_0:drum_5"] = { 144, 5 };
	dict["kit_0:drum_6"] = { 144, 6 };
	dict["kit_0:drum_7"] = { 144, 7 };

	dict["kit_1:drum_0"] = { 145, 0 };
	dict["kit_1:drum_1"] = { 145, 1 };
	dict["kit_1:drum_2"] = { 145, 2 };
	dict["kit_1:drum_3"] = { 145, 3 };
	dict["kit_1:drum_4"] = { 145, 4 };
	dict["kit_1:drum_5"] = { 145, 5 };
	dict["kit_1:drum_6"] = { 145, 6 };
	dict["kit_1:drum_7"] = { 145, 7 };
}
Resolume::Resolume(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	setupDictionary();
}
int Resolume::operator()(string element, int value)
{
	dict[element].value = value;
	sendmidi->send(dict[element], 127);
	return 0;
}
