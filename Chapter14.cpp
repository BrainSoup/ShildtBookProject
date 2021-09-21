#include <iostream>
#include "ColorText.h"
#include "Chapter14.h"

using namespace std;

//TODO: Interfaces

#pragma region class_tree

class BaseClass {
//private:
	int x = 0;
protected:
	int y = 0;
public:
	static bool show_msg;
	int z = 0;

	BaseClass(int x = 0) { 
		if (show_msg) cout << "BaseClass Constructor" << endl;
	}

	~BaseClass() {
		if (show_msg) cout << "BaseClass Destructor" << endl;
	}
};

bool BaseClass::show_msg = false;

//Private inheritance means members of base class become private members of inherited class
//This is why private inherited members still accessable in inherited class
class DerivedClass : /*private*/ BaseClass {	
public:
	BaseClass::z;	// Access declaration( return z access to public)
	BaseClass::show_msg;

	DerivedClass(int x, int y) : BaseClass(x) {	//Sending param to its base constructor
		if (BaseClass::show_msg) cout << "DerivedClass Constructor" << endl;
	}

	~DerivedClass() {
		if (BaseClass::show_msg) cout << "DerivedClass Destructor" << endl;
	}

	void SomeMethod()
	{
		cout << "y=" << y << ", z=" << z << endl;
	}

};

//Public inheritance doesn't change accessability modifiers
class DerivedDerivedClass : public DerivedClass {
protected:
	//BaseClass::y;	// Access declaration can be defined only in class that change access modifiers

public:

	DerivedDerivedClass(int x, int y, int z) : DerivedClass(x, y) {	//Sending param to its base constructor
		if (show_msg) cout << "DerivedDerivedClass Constructor" << endl;
	}

	~DerivedDerivedClass() {
		if (show_msg) cout << "DerivedDerivedClass Destructor" << endl;
	}
	//y and z are not accessable due to they are private members of DerivedClass
	void SomeOtherMethod()	{
		//cout << "y=" << y << endl;	//y is private member of DerivedClass
		cout << "y is unaccessable due to private inheritance of DerivedClass" << endl;
		cout << "z=" << z << endl;	//z is public again cause of Access declaration
	}
};

class DerivedClass1 : public BaseClass {
public:
	DerivedClass1(int x, int y) : BaseClass(x)	{
		if (show_msg) cout << "DerivedClass1 Constructor" << endl;
	}

	~DerivedClass1() {
		if (show_msg) cout << "DerivedClass1 Destructor" << endl;
	}
};

class MultipleDerivedClass : public DerivedClass, public DerivedClass1 {

public:
	MultipleDerivedClass(int x, int y, int z) : DerivedClass(x, y), DerivedClass1(x, y) {	//Sending param to its base constructor
		if (show_msg) cout << "MultipleDerivedClass Constructor" << endl;
	}

	~MultipleDerivedClass() {
		if (show_msg) cout << "MultipleDerivedClass Destructor" << endl;
	}
};

class VirtualDerivedClass1 : virtual public BaseClass {
public:
	VirtualDerivedClass1(int x, int y) : BaseClass(x) {}
};

class VirtualDerivedClass2 : virtual public BaseClass {
public:
	VirtualDerivedClass2(int x, int y) : BaseClass(x) {}
};

class VirtualMultipleDerivedClass : public VirtualDerivedClass1, public VirtualDerivedClass2 {
public:
	VirtualMultipleDerivedClass(int x, int y) : VirtualDerivedClass1(x, y), VirtualDerivedClass2(x, y) {
	}
};

#pragma endregion

void Chapter14Func()
{
	PrintColorText("\nChapter 14. Inheritance\n");

	BaseClass::show_msg = true;
	cout << "Constructor/Destructor execution of inherited classes: \n\n";
	DerivedDerivedClass *ddc = new DerivedDerivedClass(0, 1, 2);
	delete ddc;

	cout << "\nConstructor/Destructor execution of multiple inherited classes: \n";
	cout << "class MultipleDerivedClass : public DerivedClass, public BaseClass \n\n";
	MultipleDerivedClass *mdc = new MultipleDerivedClass(0, 1, 2);
	delete mdc;
	BaseClass::show_msg = false;

	cout << "\nStatic field inheritance:\n\n";	//Work as expected
	BaseClass::show_msg = false; 
	cout << "BaseClass::show_msg = false; ==>" << endl;
	cout << "BaseClass::show_msg = " << BaseClass::show_msg << ", DerivedClass::show_msg = " << DerivedClass::show_msg << endl;
	DerivedClass::show_msg = true;
	cout << "DerivedClass::show_msg = true; ==>" << endl;
	cout << "BaseClass::show_msg = " << BaseClass::show_msg << ", DerivedClass::show_msg = " << DerivedClass::show_msg << endl;
	DerivedClass1::show_msg = false;
	cout << "DerivedClass1::show_msg = false; ==>" << endl;
	cout << "BaseClass::show_msg = " << BaseClass::show_msg << ", DerivedClass::show_msg = " << DerivedClass::show_msg << endl;

	cout << "\nInheritance accessability modifiers:\n\n";
	DerivedDerivedClass dd(1, 2, 3);
	cout << "DerivedClass::SomeMethod();" << endl;
	dd.SomeMethod();
	cout << "DerivedDerivedClass::SomeOtherMethod();" << endl;
	dd.SomeOtherMethod();
	//dd.y = 0;	//DerivedClass::y becomes private member (not accessable from outer code)
	dd.z = 0;	//DerivedClass::z is still public due to access declaration

	cout << "\nMultiple inherited class members:\n\n";
	MultipleDerivedClass md(0, 0, 0);
	cout << "MultipleDerivedClass now have 2 copies of x, y and z" << endl;
	md.DerivedClass::z = 1;
	md.DerivedClass1::z = 2;
	cout << "md.DerivedClass1::z = " << md.DerivedClass1::z << ", md.DerivedClass::z = " << md.DerivedClass::z << endl;

	cout << "\nVirtual inheritance:\n\n";
	VirtualMultipleDerivedClass vmd(0,0);
	vmd.VirtualDerivedClass2::z = 1;
	cout << "vmd.VirtualDerivedClass2::z = 1; \nvmd.VirtualDerivedClass1::z = " << vmd.VirtualDerivedClass1::z << endl;
}