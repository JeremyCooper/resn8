//drumModel.cpp
using namespace std;
class Drums
{
public:
	Drums(SendDmx *);
	//Drums(SendDMX *);
	void setupDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
	SendDmx * senddmx;
};
/////////////////////
void Drums::setupDictionary()
{
	dict["kit_0:drum_0:R"] = { 1, 0 };
	dict["kit_0:drum_0:G"] = { 1, 1 };
	dict["kit_0:drum_0:B"] = { 1, 2 };

	dict["kit_0:drum_1:R"] = { 1, 3 };
	dict["kit_0:drum_1:G"] = { 1, 4 };
	dict["kit_0:drum_1:B"] = { 1, 5 };

	dict["kit_0:drum_2:R"] = { 1, 6 };
	dict["kit_0:drum_2:G"] = { 1, 7 };
	dict["kit_0:drum_2:B"] = { 1, 8 };

	dict["kit_1:drum_0:R"] = { 1, 9 };
	dict["kit_1:drum_0:G"] = { 1, 10 };
	dict["kit_1:drum_0:B"] = { 1, 11 };

	dict["kit_1:drum_1:R"] = { 1, 12 };
	dict["kit_1:drum_1:G"] = { 1, 13 };
	dict["kit_1:drum_1:B"] = { 1, 14 };

	dict["kit_1:drum_2:R"] = { 1, 15 };
	dict["kit_1:drum_2:G"] = { 1, 16 };
	dict["kit_1:drum_2:B"] = { 1, 17 };
}
Drums::Drums(SendDmx * senddmx) : senddmx(senddmx) //SendMidi * sendmidi) : sendmidi(sendmidi)
{
	setupDictionary();
}
int Drums::operator()(string element, int value)
{
	dict[element].value = value;

	cout << "drumModel sending: " << dict[element].channel
		<< ", " << dict[element].note << ", " << value << endl;

	senddmx->send(dict[element], value);
	return 0;
}
