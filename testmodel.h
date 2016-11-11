//testmodel.h
//
//test model do not reply

class Test : public Model 
{
public:
	Test() {}
	void blah();
};

void Test::blah()
{
	cout << "hello" << endl;
}
