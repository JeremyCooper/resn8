//apc80.h
#include "../Models/testmodel.cpp"
#include "../Models/feedbackClass.cpp"
using namespace std;
class APC80
{
public:
	APC80(SendMidi *);
	//Mappable functions//
	/* relative */
	int red(int, vector<int>);
	int green(int, vector<int>);
	int blue(int, vector<int>);
	int red_bg(int, vector<int>);
	int green_bg(int, vector<int>);
	int blue_bg(int, vector<int>);
	int opacity(int, vector<int>);
	int opacity_bg(int, vector<int>);
	int speed(int, vector<int>);
	int speed_bg(int, vector<int>);
	int playback(int, vector<int>);
	int playback_bg(int, vector<int>);
	int width(int, vector<int>);
	int height(int, vector<int>);
	int scale(int, vector<int>);
	int rotateX(int, vector<int>);
	int rotateY(int, vector<int>);
	int rotateZ(int, vector<int>);
	int blend(int, vector<int>);
	int effect(int, vector<int>);
	/* absolute */
	int previewForward(int, vector<int>);
	int previewBackward(int, vector<int>);
	int select(int, vector<int>);

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
	int selectLayer(int, vector<int>);
	int selectLayer_bg(int, vector<int>);
	//////////////////////
	void bpmManager();
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
	Test model;
private:
	//SendMidi * sendmidi;
	Feedback feedback;
	vector<bool> active_binds;
	vector<int> anim_threads;
	map<string, Ptr> hooks;
	vector<pair<Ptr, vector<int>>> operation_stack;
	vector<tuple<Ptr, vector<int>, int>> smart_binds;
	vector<vector<tuple<Ptr, vector<int>, int>>> execution_stacks;
};
