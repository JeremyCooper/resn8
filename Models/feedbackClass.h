//feedbackClass.h
#include <utility>
using namespace std;
struct savedClipViewStruct
{
	typedef pair<int,int> intPair;
	vector<vector<intPair>> scvs;
};
class Feedback
{
public:
	Feedback(SendMidi *);
	void fillDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
	SendMidi * sendmidi;
};
