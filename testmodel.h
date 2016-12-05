//testmodel.h
using namespace std;
struct Reference
{
	Reference() {}
	Reference(int channel, int note) : channel(channel), note(note) {}
	int channel, note;
};
class Test
{
public:
	Test(int (*sendMidi) (Reference, int));
	void fillDictionary();
	int operator()(string, int);
private:
	int (*sendMidi) (Reference, int); //pointer to sendMidi function
	map<string, Reference> dict;
};
