//apc80.h
using namespace std;
class APC80
{
public:
	APC80(int (*sendMidi) (Reference, int));
	//Mappable functions//
	int test(int, vector<int>);
	int bindSlot(int, vector<int>);
	int smartBind(int, vector<int>);
	int ignoreMidi(int, vector<int>);
	int resetLayer(int, vector<int>);
	int changeGroupPage(int, vector<int>);
	int changeLayer(int, vector<int>);
	int changeBackgroundLayer(int, vector<int>);
	int changeCurrentSCP(int, vector<int>);
	int red(int, vector<int>);
	int green(int, vector<int>);
	int blue(int, vector<int>);
	int red_bg(int, vector<int>);
	int green_bg(int, vector<int>);
	int blue_bg(int, vector<int>);
	//////////////////////
	typedef int (APC80::*Ptr) (int, vector<int>);
	int send(string, int);
	void addOperation(Ptr, vector<int>);
	void updateFeedback(vector<string>&, string);
	void updateFeedback(vector<string>, map<string, int>&);
	void setupStates();
	void setupGroups();
	void setupPageDisplayValues();
	void setupFeedback();
	void fillHooks();
	Ptr returnPointer(string operation_name);
	//Wreorder made me do it!
	map<string, int> states;
	vector<map<string, int>> pageDisplayValues;
	vector<vector<string>> group_members;
private:
	int (*sendMidi) (Reference, int);
	Test model;
	Feedback feedback;
	map<string, Ptr> hooks;
	map<string, Reference> dict;
	vector<pair<Ptr, vector<int>>> operation_stack;
	vector<tuple<Ptr, vector<int>, int>> smart_binds;
};
