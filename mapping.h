//mapping.h
//
//

template<class T> class Member_Pointer
{
public:
	Member_Pointer(T operation);
	void set_pointer(T operation);
private:
	T operation;
};
template<class T> Member_Pointer<T>::Member_Pointer(T operation)
{
	this->operation = operation;
}

template<class T> void Member_Pointer<T>::set_pointer(T operation)
{
	this->operation = operation;
}
