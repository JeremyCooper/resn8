//feedbackClass.h
using namespace std;
class Feedback
{
public:
	Feedback(int (*sendMidi) (Reference, int));
	void fillDictionary();
	int operator()(string, int);
private:
	int (*sendMidi) (Reference, int);
	map<string, Reference> dict;
};
