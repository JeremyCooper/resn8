#include "../Models/drumModel.cpp"
using namespace std;
class Controller
{
public:
	int drum(int, vector<int>);
///////////////////////////
	Controller(SendDmx *);

	typedef int (Controller::*Ptr) (int, vector<int>);

	void setupHooks();
	void setupFeedback();
	void setupStates();
	Ptr returnPointer(string);


	map<string, int> states;
private:
	Drums model;
	map<string, Ptr> hooks;	
};
