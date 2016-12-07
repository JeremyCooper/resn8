//apc80.h
using namespace std;
class APC80
{
public:
	APC80(int (*sendMidi) (Reference, int));
	//Mappable functions//
	int resetLayer(int value, vector<int> args);
	int changeLayer(int value, vector<int> args);
	int changeBackgroundLayer(int value, vector<int> args);
	int changeCurrentSCP(int value, vector<int> args);
	int red(int value, vector<int> args);
	int green(int value, vector<int> args);
	int red_bg(int value, vector<int> args);
	//////////////////////
	int send(string, int);
	void setupFeedback();
	void updateFeedback(vector<string>);
	void setupStates();
	void fillHooks();
	typedef int (APC80::*Ptr) (int, vector<int>);
	Ptr returnPointer(string operation_name);
	//Wreorder made me do it!
	int page;
private:
	int (*sendMidi) (Reference, int);
	Test model;
	Feedback feedback;
	map<string, Ptr> hooks;
	map<string, Reference> dict;
	map<string, int> states;
};
