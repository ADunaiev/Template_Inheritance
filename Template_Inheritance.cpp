#include <iostream>
using namespace std;

//Задание 3.
//Используя механизм шаблонного наследования создайте иерархию классов.
//Базовый класс под названием base имеет следующие переменные - члены:
//1. T1 value1; // некоторое значение;
//2. T2 value2; // некоторое значение.
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


template <class T1, class T2, class T5, class T6>
class child2 : public base <T1, T2>
{
	T5 value5;
	T6 value6;
public:
	child2();
	child2(T1 value1P, T2 value2P, T5 value5P, T6 value6P);
	~child2();
};

template <class T1, class T2, class T5, class T6>
child2<T1, T2, T5, T6>::child2()
	: base <T1, T2>(), value5{ T5() }, value6{ T6() }
{
	cout << "Object child2 constructed\n";
}

template <class T1, class T2, class T5, class T6>
child2<T1, T2, T5, T6>::child2(T1 value1P, T2 value2P, T5 value5P, T6 value6P)
	: base<T1, T2>(value1P, value2P), value5{ value5P }, value6{ value6P }
{
	cout << "Object child2 constructed\n";
}

template <class T1, class T2, class T5, class T6>
child2<T1, T2, T5, T6>::~child2()
{
	cout << "Object child2 destructed\n";
}



int main()
{
	base<int, long> obj1;
	child<int, long, double, float> obj2{1, 2, 3, 4};
	child2<int, long, char, bool> obj3;

	return 0;
}