//testmodel.h
using namespace std;
class Test
{
public:
	Test(SendMidi *);
	void fillDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
	SendMidi * sendmidi;
};
