//animationthread.cpp
#include <thread>
using namespace std;

template <typename T, typename O>
class AnimationThread
{
public:
	AnimationThread(T ptr, O obj, pair<int, vector<int>> m, pair<bool, bool> * peers) :
		ptr(ptr), obj(obj), m(m), peers(peers) {}
	int operator()()
	{
		cout << m.second.size() << endl;
		thread t(&AnimationThread::run_thread, *this);
		t.detach();
		return 0;
	}
	void run_thread()
	{
		for (const auto& i : m.second)
		{
			if (peers.first == true)
				break;
			(obj->*ptr)(i, vector<int> {0});
			this_thread::sleep_for(chrono::milliseconds(m.first));
		}
	}
private:
	T ptr;
	O obj;
	pair<int, vector<int>> m;
	pair<bool, bool> * peers;
};
