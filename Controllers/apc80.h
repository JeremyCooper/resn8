//apc80.h
#include "../Models/testmodel.cpp"
#include "../Models/feedbackClass.cpp"
using namespace std;
class APC80
{
public:
	APC80(SendMidi *);
	//Mappable functions//
	int test(int, vector<int>);
	int bpmSlot(int, vector<int>);
	int bpmTap(int, vector<int>);
	//(stage, param)
	int smartBind(int, vector<int>);
	int exStack(int, vector<int>);
	int ignoreMidi(int, vector<int>);
	int resetLayer(int, vector<int>);
	//{target group, new page, direction?}
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
	int selectLayer(int, vector<int>);
	int selectLayer_bg(int, vector<int>);
	int opacity(int, vector<int>);
	int opacity_bg(int, vector<int>);
	int speed(int, vector<int>);
	int speed_bg(int, vector<int>);
	int playback(int, vector<int>);
	int playback_bg(int, vector<int>);
	int selectClip(int, vector<int>);
	int selectClip_bg(int, vector<int>);
	int previewClip(int, vector<int>);
	int previewClip_bg(int, vector<int>);
	//////////////////////
	typedef int (APC80::*Ptr) (int, vector<int>);
	int send(string, int);
	void addOperation(Ptr, vector<int>);
	void updateFeedback(vector<string>&, string);
	void updateFeedback(vector<string>&, map<string, int>&);
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
	string bindMode;
private:
	//SendMidi * sendmidi;
	Test model;
	Feedback feedback;
	vector<bool> active_binds;
	vector<int> anim_threads;
	map<string, Ptr> hooks;
	vector<pair<Ptr, vector<int>>> operation_stack;
	vector<tuple<Ptr, vector<int>, int>> smart_binds;
	vector<vector<tuple<Ptr, vector<int>, int>>> execution_stacks;
};
