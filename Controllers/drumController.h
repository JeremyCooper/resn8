#include "../Models/drumModel.cpp"
#include "../Models/resModel.cpp"
using namespace std;
class Controller
{
public:
	int mode(int, vector<int>);
	int drum(int, vector<int>);
///////////////////////////
	Controller(SendMidi *);
	Controller(SendMidi *, SendDmx *);

	typedef int (Controller::*Ptr) (int, vector<int>);

	void drumOff(string);

	void setupHooks();
	void setupFeedback();
	void setupStates();
	Ptr returnPointer(string);


	map<string, int> states;
private:
	Drums model;
//	Resolume resolume;
	map<string, Ptr> hooks;	
	string lastDrum;
};
