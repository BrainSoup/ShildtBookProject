#include <iostream>
#include "ColorText.h"
#include "Chapter15.h"

using namespace std;

#pragma region class_tree
class Base
{
public:
	virtual void VirtualPrint(){
		cout << "\"Base.VirtualPrint()\"" << endl;
	}
};

class Derived : public Base	//public inheritance needed to make type polimorhpism
{
public:
	void VirtualPrint() {
		cout << "\"Derived.VirtualPrint()\"" << endl;
	}
};

class DerivedDerived : public Derived
{
public:
	void VirtualPrint() {
		cout << "\"DerivedDerived.VirtualPrint()\"" << endl;
	}
};

//Classes that contains pure virtual methods are abstract
//No instances of this class can't be created
class PureVirtual
{
public:
	virtual int DoSomething() = 0;	//Pure virtual methos
};

class Derived1 : public PureVirtual
{
	int DoSomething() { return 0; }	//Pure virtual fuctions must be implemented in derived classes
};
#pragma endregion

void Chapter15Func()
{
	PrintColorText("\nChapter 15. Polimorphism\n");

	Base b;
	Derived d;
	DerivedDerived dd;

	PrintColorText("\nVirtual functions", TextColor::BlueText);

	cout << "\nExecution virtual function from value:" << endl;
	//Execution virtual function from value
	cout << "b.VirtualPrint() ";
	b.VirtualPrint();
	cout << "d.VirtualPrint() ";
	d.VirtualPrint();
	cout << "dd.VirtualPrint() ";
	dd.VirtualPrint();

	cout << "\nExecution virtual function from pointer:"<<endl;
	//Execution virtual function from pointer
	cout << "&b->VirtualPrint() ";
	(&b)->VirtualPrint();
	cout << "&d->VirtualPrint() ";
	(&d)->VirtualPrint();
	cout << "&dd->VirtualPrint() ";
	(&dd)->VirtualPrint();

	cout << "\nExecution virtual function from value using polimorhpism:" << endl;
	//Execution virtual function from value using polimorhpism
	cout << "((Base)b).VirtualPrint() ";
	((Base)b).VirtualPrint();
	cout << "((Base)d).VirtualPrint() ";
	((Base)d).VirtualPrint();
	cout << "((Base)dd).VirtualPrint() ";
	((Base)dd).VirtualPrint();

	//Abstruct classes:
	Derived1 d1;
	//PureVirtual pv;	//object of abstract class type "PureVirtual" is not allowed
	PureVirtual *p_pv = &d1;	//PureVirtual types is allowed to use as pointers or references
}