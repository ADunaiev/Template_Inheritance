#include <iostream>
using namespace std;

//������� 3.
//��������� �������� ���������� ������������ �������� �������� �������.
//������� ����� ��� ��������� base ����� ��������� ���������� - �����:
//1. T1 value1; // ��������� ��������;
//2. T2 value2; // ��������� ��������.
//�������� ������� No12
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
	cout << "\nObject base constructed" << endl;
}

template <class T1, class T2>
base<T1, T2>::base(T1 value1P, T2 value2P) : value1{ value1P}, value2{ value2P}
{cout << "\nObject base constructed" << endl; }

template <class T1, class T2>
base<T1, T2>::~base()
{
	cout << "Object base destructed" << endl;
}


int main()
{
	base<int, long> obj1;

	return 0;
}