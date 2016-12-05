//apc80.h
using namespace std;
class APC80
{
public:
	APC80(int (*sendMidi) (Reference, int));
	//Mappable functions//
	int resetLayer(int value, vector<int> args);
	int abstractfunction(int value, vector<int> args);
	//////////////////////
	int send(string, int);
	void fillHooks();
	void fillDictionary();
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
};
