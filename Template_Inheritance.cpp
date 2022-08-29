#include <iostream>
using namespace std;

//Задание 3.
//Используя механизм шаблонного наследования создайте иерархию классов.
//Базовый класс под названием base имеет следующие переменные - члены:
//1. T1 value1; // некоторое значение;
//2. T2 value2; // некоторое значение.
//Домашнее задание No12
//Потомок под названием child содержит дополнительные переменные - члены:
//1. T3 value3;
//2. T4 value4.
//Потомок под названием child2 добавляет такие переменные - члены:
//1. T5 value5;
//2. T6 value6.
//Каждый класс имеет необходимый набор конструкторов, деструкторов, функций 
//- членов для работы со структурой класса.
//В main протестировать работу класса.

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