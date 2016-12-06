//testmodel.h
using namespace std;
struct Reference
{
	Reference() {}
	Reference(int channel, int note, int initial) :
		channel(channel), note(note), initial(initial) {}
	int channel, note, initial;
};
class Test
{
public:
	Test(int (*sendMidi) (Reference, int));
	void fillDictionary();
	int operator()(string, int);
	map<string, Reference> dict;
private:
	int (*sendMidi) (Reference, int); //pointer to sendMidi function
};
