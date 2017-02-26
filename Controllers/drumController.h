#include "../Models/drumModel.cpp"
#include "../Models/resModel.cpp"
using namespace std;
typedef chrono::high_resolution_clock Clock;
typedef chrono::milliseconds mills;
class Controller
{
public:
	int mode(int, vector<int>);
	int drum(int, vector<int>);
///////////////////////////
	//Controller(SendMidi *);
#ifdef dmx_out
	Controller(SendMidi *, SendDmx *);
#endif

	typedef int (Controller::*Ptr) (int, vector<int>);

	void drumOff(string);
	void clock_thread();
	void strobe(string);
	void modeThread(int);

	void setupHooks();
	void setupFeedback();
	void setupStates();
	void setupColors();
	void setupLights();
	Ptr returnPointer(string);


	map<string, int> states;
private:
	Drums model;
	Resolume resolume;
	map<string, Ptr> hooks;	
	string lastDrum;
	string lastDrum2;
	vector<vector<tuple<int, int, int, int, int>>> colorschemes;
	vector<tuple<int, int, int, int, int>> colorscheme2;
	vector<tuple<int, int, int, int, int>> colorscheme3;
	vector<pair<int, tuple<int, int, int, int, int>>> dmx_addresses;
	chrono::time_point<Clock> last_hit;
	chrono::time_point<Clock> last_hit2;
	chrono::time_point<Clock> modeStart;
	bool newMode;
};
