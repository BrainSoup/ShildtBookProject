#include <iostream>
#include "ColorText.h"
#include "Chapter20.h"

using namespace std;

#pragma region ExampleEntities

class SomeClass 
{
	const int c = 0;
	int i = 0;
	mutable int j = 0;
public:
	SomeClass(int constVal) : c(constVal)	//const value members can be initialized in constructor
	{
		//c = constVal;	//Error: inside functions and constructor can't modify const values
	}
	int Geti() const { return i; }
	//void Seti(int val) const { i=val; }	//Error: const function members can't modify value members
	int Getj() const { return i; }
	void Setj(int val) const { j=val; }		//const function members can modify mutable value members
	//void ConstFunc(int val) const { NotConstFunc(val); }	//Error: const func member can call only const func members
	void NotConstFunc(int val) { i = val; j = val; }
};

void Print(int i)
{
	cout << "Print: " << i << endl;
}

//Named namespace
namespace Test {
	int i;
}

//Unnamed namespace
namespace{
	int j;
}
#pragma endregion

void Chapter20Func()
{
	PrintColorText("\nChapter 20. Namespaces, function pointers\n");

	cout << "Namespaces:" << endl;
	//In named namespaces must use name prefix
	cout << "Test::i = " << Test::i << endl;
	Test::i = 20;
	//i = 20;	//Compile error

	//Unnamed namespaces allow using without prefix
	//But only can be used in same file
	j = 90;
	
	cout << "\nFunction pointers:" << endl;
	void (*p)(int i);	//pointer to func(int i)
	p = Print;
	p(10);	//Execution of func pointer
	(*p)(20);	//Preferable way of func pointer execution due to code readability

	cout << "\nConst/mutable class instructions:" << endl;
	SomeClass s = 10;
	cout << "SomeClass j = " << s.Getj() << endl;
	s.Setj(10);
	cout << "SomeClass j = " << s.Getj() << " const member funcs can modify only mutable value members" << endl;
}