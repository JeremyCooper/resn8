//threads.cpp
#include <thread>
using namespace std;

template <typename T, typename O>
class AnimationThread
{
public:
	AnimationThread(T ptr, O obj, pair<int, vector<int>> m, int * current_thread, vector<int> params) :
		ptr(ptr), obj(obj), m(m), current_thread(current_thread), params(params)
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
			(obj->*ptr)(i, params);
			this_thread::sleep_for(chrono::milliseconds(m.first));
		}
	}
private:
	T ptr;
	O obj;
	pair<int, vector<int>> m;
	int thread_id;
	int * current_thread;
	vector<int> params;
};

class BpmThread
{
public:
/*
   * Execute all binds on phase 0, wait, execute all binds on phase 1, etc.

   * "Bind" object should replace the relatively ad-hoc data-type based
     storage approach currently being used.

   * When bind is "latched" to the bpmManager, bind object is copied to the
     bpmManager's internals.

   * "Phase"s will be vector<vector<Bind>>
*/
	BpmThread()
	{
		currentPhase = 0;
	}
	void operator()()
	{
		thread t(&BpmThread::run_thread, *this);
		t.detach();
	}
	void run_thread()
	{
	}
private:
	int currentPhase;
};
