//animationthread.cpp
#include <thread>
using namespace std;

template <typename T, typename O>
class AnimationThread
{
public:
	AnimationThread(T ptr, O obj, pair<int, vector<int>> m, int * current_thread) :
		ptr(ptr), obj(obj), m(m), current_thread(current_thread)
	{
		if (*current_thread > 50) //FIXME
		{	
			thread_id = 0;
		} else {
			thread_id = *current_thread+1;
		}
		cout << "========================================" << endl << "current thread: " << thread_id << endl;
	}
	int operator()()
	{
		*current_thread = thread_id;
		thread t(&AnimationThread::run_thread, *this);
		t.detach();
		return 0;
	}
	void run_thread()
	{
		for (const auto& i : m.second)
		{
			if (*current_thread != thread_id)
				break;
			(obj->*ptr)(i, vector<int> {0});
			this_thread::sleep_for(chrono::milliseconds(m.first));
		}
	}
private:
	T ptr;
	O obj;
	pair<int, vector<int>> m;
	int thread_id;
	int * current_thread;
};
