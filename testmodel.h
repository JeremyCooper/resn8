//testmodel.h
//
//test model do not reply

class Test : public Model 
{
public:
	Test() {}
	void blah();
	void lala()
	{
		cout << "LALALALLA" << endl;
	}
};

void Test::blah()
{
	cout << "BLAH BLAH BLAH" << endl;
}
