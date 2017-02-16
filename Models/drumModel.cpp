//drumModel.cpp
using namespace std;
class Drums
{
public:
	Drums(SendMidi *);
#ifdef dmx_out
	Drums(SendMidi *, SendDmx *);
#endif
	void setupDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
	SendMidi * sendmidi;
#ifdef dmx_out
	SendDmx * senddmx;
#endif
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
Drums::Drums(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	setupDictionary();
}
#ifdef dmx_out
Drums::Drums(SendMidi * sendmidi, SendDmx * senddmx) : sendmidi(sendmidi), senddmx(senddmx)
{
	setupDictionary();
}
#endif
int Drums::operator()(string element, int value)
{
	dict[element].value = value;
#ifdef dmx_out
	senddmx->send(dict[element], value);
#endif
	sendmidi->send(dict[element], value);
	return 0;
}
