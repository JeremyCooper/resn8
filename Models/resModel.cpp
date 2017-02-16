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
	dict["kit_0:drum_0"] = { 1, 0 };
}
Resolume::Resolume(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	setupDictionary();
}
int Resolume::operator()(string element, int value)
{
	dict[element].value = value;
	cout << "resModel sending: " << dict[element].channel
		<< ", " << dict[element].note << ", " << value << endl;
	sendmidi->send(dict[element], value);
	return 0;
}
