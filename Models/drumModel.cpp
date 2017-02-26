//drumModel.cpp
using namespace std;
class Drums
{
public:
//	Drums(SendMidi *);
#ifdef dmx_out
	Drums(SendDmx *);
#endif
	void setupDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
//	SendMidi * sendmidi;
#ifdef dmx_out
	SendDmx * senddmx;
#endif
};
/////////////////////
void Drums::setupDictionary()
{
	dict["stage_0:R"]      = { 1, 0 };
	dict["stage_0:G"]      = { 1, 0 };
	dict["stage_0:B"]      = { 1, 0 };
	dict["stage_0:A"]      = { 1, 0 };

	dict["stage_1:R"]      = { 1, 0 };
	dict["stage_1:G"]      = { 1, 0 };
	dict["stage_1:B"]      = { 1, 0 };
	dict["stage_1:A"]      = { 1, 0 };

	dict["kit_0:drum_0:A"] = { 1, 0 };
	dict["kit_0:drum_0:R"] = { 1, 1 };
	dict["kit_0:drum_0:G"] = { 1, 2 };
	dict["kit_0:drum_0:B"] = { 1, 3 };
	dict["kit_0:drum_0:Y"] = { 1, 4 };
	dict["kit_0:drum_0:W"] = { 1, 5 };

	dict["kit_0:drum_1:A"] = { 1, 10 };
	dict["kit_0:drum_1:R"] = { 1, 11 };
	dict["kit_0:drum_1:G"] = { 1, 12 };
	dict["kit_0:drum_1:B"] = { 1, 13 };
	dict["kit_0:drum_1:Y"] = { 1, 14 };
	dict["kit_0:drum_1:W"] = { 1, 15 };

	dict["kit_0:drum_2:A"] = { 1, 20 };
	dict["kit_0:drum_2:R"] = { 1, 21 };
	dict["kit_0:drum_2:G"] = { 1, 22 };
	dict["kit_0:drum_2:B"] = { 1, 23 };
	dict["kit_0:drum_2:Y"] = { 1, 24 };
	dict["kit_0:drum_2:W"] = { 1, 25 };

	dict["kit_0:drum_3:A"] = { 1, 30 };
	dict["kit_0:drum_3:R"] = { 1, 31 };
	dict["kit_0:drum_3:G"] = { 1, 32 };
	dict["kit_0:drum_3:B"] = { 1, 33 };
	dict["kit_0:drum_3:Y"] = { 1, 34 };
	dict["kit_0:drum_3:W"] = { 1, 35 };

	dict["kit_0:drum_4:A"] = { 1, 40 };
	dict["kit_0:drum_4:R"] = { 1, 41 };
	dict["kit_0:drum_4:G"] = { 1, 42 };
	dict["kit_0:drum_4:B"] = { 1, 43 };
	dict["kit_0:drum_4:Y"] = { 1, 44 };
	dict["kit_0:drum_4:W"] = { 1, 45 };
	
	dict["kit_0:drum_5:A"] = { 1, 50 };
	dict["kit_0:drum_5:R"] = { 1, 51 };
	dict["kit_0:drum_5:G"] = { 1, 52 };
	dict["kit_0:drum_5:B"] = { 1, 53 };
	dict["kit_0:drum_5:Y"] = { 1, 54 };
	dict["kit_0:drum_5:W"] = { 1, 55 };

	dict["kit_0:drum_6:A"] = { 1, 60 };
	dict["kit_0:drum_6:R"] = { 1, 61 };
	dict["kit_0:drum_6:G"] = { 1, 62 };
	dict["kit_0:drum_6:B"] = { 1, 63 };
	dict["kit_0:drum_6:Y"] = { 1, 64 };
	dict["kit_0:drum_6:W"] = { 1, 65 };

	dict["kit_0:drum_7:A"] = { 1, 70 };
	dict["kit_0:drum_7:R"] = { 1, 71 };
	dict["kit_0:drum_7:G"] = { 1, 72 };
	dict["kit_0:drum_7:B"] = { 1, 73 };
	dict["kit_0:drum_7:Y"] = { 1, 74 };
	dict["kit_0:drum_7:W"] = { 1, 75 };

	dict["kit_1:drum_0:A"] = { 1, 80 };
	dict["kit_1:drum_0:R"] = { 1, 81 };
	dict["kit_1:drum_0:G"] = { 1, 82 };
	dict["kit_1:drum_0:B"] = { 1, 83 };
	dict["kit_1:drum_0:Y"] = { 1, 84 };
	dict["kit_1:drum_0:W"] = { 1, 85 };

	dict["kit_1:drum_1:A"] = { 1, 90 };
	dict["kit_1:drum_1:R"] = { 1, 91 };
	dict["kit_1:drum_1:G"] = { 1, 92 };
	dict["kit_1:drum_1:B"] = { 1, 93 };
	dict["kit_1:drum_1:Y"] = { 1, 94 };
	dict["kit_1:drum_1:W"] = { 1, 95 };

	dict["kit_1:drum_2:A"] = { 1, 100 };
	dict["kit_1:drum_2:R"] = { 1, 101 };
	dict["kit_1:drum_2:G"] = { 1, 102 };
	dict["kit_1:drum_2:B"] = { 1, 103 };
	dict["kit_1:drum_2:Y"] = { 1, 104 };
	dict["kit_1:drum_2:W"] = { 1, 105 };

	dict["kit_1:drum_3:A"] = { 1, 110 };
	dict["kit_1:drum_3:R"] = { 1, 111 };
	dict["kit_1:drum_3:G"] = { 1, 112 };
	dict["kit_1:drum_3:B"] = { 1, 113 };
	dict["kit_1:drum_3:Y"] = { 1, 114 };
	dict["kit_1:drum_3:W"] = { 1, 115 };

	dict["kit_1:drum_4:A"] = { 1, 120 };
	dict["kit_1:drum_4:R"] = { 1, 121 };
	dict["kit_1:drum_4:G"] = { 1, 122 };
	dict["kit_1:drum_4:B"] = { 1, 123 };
	dict["kit_1:drum_4:Y"] = { 1, 124 };
	dict["kit_1:drum_4:W"] = { 1, 125 };
	
	dict["kit_1:drum_5:A"] = { 1, 130 };
	dict["kit_1:drum_5:R"] = { 1, 131 };
	dict["kit_1:drum_5:G"] = { 1, 132 };
	dict["kit_1:drum_5:B"] = { 1, 133 };
	dict["kit_1:drum_5:Y"] = { 1, 134 };
	dict["kit_1:drum_5:W"] = { 1, 135 };

	dict["kit_1:drum_6:A"] = { 1, 140 };
	dict["kit_1:drum_6:R"] = { 1, 141 };
	dict["kit_1:drum_6:G"] = { 1, 142 };
	dict["kit_1:drum_6:B"] = { 1, 143 };
	dict["kit_1:drum_6:Y"] = { 1, 144 };
	dict["kit_1:drum_6:W"] = { 1, 145 };

	dict["kit_1:drum_7:A"] = { 1, 150 };
	dict["kit_1:drum_7:R"] = { 1, 151 };
	dict["kit_1:drum_7:G"] = { 1, 152 };
	dict["kit_1:drum_7:B"] = { 1, 153 };
	dict["kit_1:drum_7:Y"] = { 1, 154 };
	dict["kit_1:drum_7:W"] = { 1, 155 };
}
/*Drums::Drums(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	setupDictionary();
}*/
#ifdef dmx_out
Drums::Drums(SendDmx * senddmx) : senddmx(senddmx)
{
	setupDictionary();
}
#endif
int Drums::operator()(string element, int value)
{
	dict[element].value = value;
#ifdef dmx_out
//	cout << element << ", " << value << endl;
	senddmx->send(dict[element], value);
#endif
	return 0;
}
