#include <iostream>
#include "ColorText.h"
#include "Chapter16.h"

using namespace std;

#pragma region Templates

//Simple template function
//In place of keyword typename can also be class
template <typename X=int> void Swap(X* one, X* two)
{
	cout << "Template func Swap" << endl;
	X tmp = *one;
	*one = *two;
	*two = tmp;
}

//explicitly defined template
template <> void Swap<float>(float *one, float *two)
{
	cout << "Explicitly defined template func Swap<float>" << endl;
	float tmp = *one;
	*one = *two;
	*two = tmp;
}

//Simple template class
//int size is not type param used in class as value
//As not type param only int and pointers and refs can be used
template <class X=int, int size=100> class myQueue	//Allows default type and not type param definition
{
	X array[size];
	int index;
public:
	myQueue() { index = 0; }
	bool empty() { return index == 0; }
	void put(X val);
	X get();
};

template <class X, int size> void myQueue<X, size>::put(X val)
{
	if (index < size)
		array[index++] = val;
}

template <class X, int size> X myQueue<X, size>::get()
{
	if (!index) return NULL;
	return array[--index];
}
#pragma endregion

void Chapter16Func()
{
	PrintColorText("\nChapter 16. templates\n");

	cout << "\nExample usage of template func:" << endl;
	int i1 = 5, i2 = 10;
	float f1 = 5, f2 = 10;
	Swap(&i1, &i2);
	Swap(&f1, &f2);

	cout << "\nExample usage of template class:" << endl;
	myQueue<int, 10> q;
	q.put(1); q.put(2); q.put(3);
	while (!q.empty())	cout << q.get() << " ";

	myQueue<> q1; //Use of default template params

}
