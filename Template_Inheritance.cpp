#include <iostream>
using namespace std;

//������� 3.
//��������� �������� ���������� ������������ �������� �������� �������.
//������� ����� ��� ��������� base ����� ��������� ���������� - �����:
//1. T1 value1; // ��������� ��������;
//2. T2 value2; // ��������� ��������.
//������� ��� ��������� child �������� �������������� ���������� - �����:
//1. T3 value3;
//2. T4 value4.
//������� ��� ��������� child2 ��������� ����� ���������� - �����:
//1. T5 value5;
//2. T6 value6.
//������ ����� ����� ����������� ����� �������������, ������������, ������� 
//- ������ ��� ������ �� ���������� ������.
//� main �������������� ������ ������.

template <class T1, class T2>
class base
{
protected:
	T1 value1;
	T2 value2;
public:
	base();
	base(T1 value1P, T2 value2P);
	~base();
};
template <class T1, class T2>
base<T1, T2>::base() : value1{T1()}, value2{T2()}
{
	cout << "Object base constructed" << endl;
}

template <class T1, class T2>
base<T1, T2>::base(T1 value1P, T2 value2P) : value1{ value1P}, value2{ value2P}
{cout << "Object base constructed" << endl; }

template <class T1, class T2>
base<T1, T2>::~base()
{
	cout << "Object base destructed" << endl;
}

template <class T1, class T2, class T3, class T4>
class child : public base <T1, T2>
{
	T3 value3;
	T4 value4;
public:
	child();
	child(T1 value1P, T2 value2P, T3 value3P, T4 value4P);
	~child();
};

template <class T1, class T2, class T3, class T4>
child<T1, T2, T3, T4>::child() 
	: base <T1, T2>(), value3{T3()}, value4{T4()}
{
	cout << "Object child constructed\n";
}

template <class T1, class T2, class T3, class T4>
child<T1, T2, T3, T4>::child(T1 value1P, T2 value2P, T3 value3P, T4 value4P)
	: base<T1, T2> (value1P, value2P), value3{ value3P }, value4{ value4P }
{
	cout << "Object child constructed\n";
}

template <class T1, class T2, class T3, class T4>
child<T1, T2, T3, T4>::~child()
{
	cout << "Object child destructed\n";
}




int main()
{
	base<int, long> obj1;
	child<int, long, double, float> obj2{1, 2, 3, 4};

	return 0;
}