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
	Feedback(int (*sendMidi) (Reference, int));
	void fillDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
	int (*sendMidi) (Reference, int);
};
