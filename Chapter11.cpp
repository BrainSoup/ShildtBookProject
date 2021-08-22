#include <iostream>
#include "ColorText.h"

using namespace std;

class SimpleClass11 {
//private:
	int a, b;
public:
	int* c = 0;
	SimpleClass11();
	SimpleClass11(int a); //	for one param constructor compiler create implicit conversation from param type to class type
	SimpleClass11(int a, int b);
	~SimpleClass11();
	void SomeMethod();	//Not inline
	int Get_a() { return a; }	//inline cause declared in class declaration
}global_simpleClass;	//Constructors of global objects executes before main()

//Classes
void Chapter11Func()
{
	PrintColorText("\nChapter 11. Classes (Basics)");

	//Initialize new class
	cout << "SimpleClass c = SimpleClass(); \n";
	SimpleClass11 c = SimpleClass11();

	cout << "SimpleClass *c_ptr = new SimpleClass(); \n";
	SimpleClass11 *c_ptr = new SimpleClass11();
	delete c_ptr;

	cout << "SimpleClass c1(1) \nSimpleClass c1_1{2, 3}; \nSimpleClass c1_2;\n";
	cout << "static_cast<SimpleClass>(c1_2); \nnew SimpleClass(1, 2);" << endl;
	cout << "\n1) direct-initialization" << endl;
	SimpleClass11 c1(1);
	SimpleClass11 c1_1{ 2, 3 };
	SimpleClass11 c1_2;
	//static_cast<SimpleClass>(c1_2); //no constructor call, but there is destructor call
	new SimpleClass11(4, 5);
	(SimpleClass11)6; // Only for 1 param constructor
	//Some other cases
	SimpleClass11 c1_3();	//No compile error, DO NOTHING, c1_3 not declared

	cout << "\n2) copy-initialization" << endl;
	cout << "SimpleClass c2 = 2; \nSimpleClass c2_1 = { 3, 4 }; \nSimpleClass c2_2 = SimpleClass{}" << endl;
	SimpleClass11 c2 = 2;	//	In this case compiler create implicit conversation from param type to class type
	SimpleClass11 c2_1 = { 3, 4 };
	SimpleClass11 c2_2 = SimpleClass11{};
	//Also passing object to function or returning from it
	//Some other cases

	cout << "\n3) list-initialization" << endl;
	cout << "SimpleClass c3 = {5}; \nSimpleClass c3{ 3, 4 }; \nSimpleClass{};" << endl;
	SimpleClass11 c3 = {5};
	SimpleClass11 c3_1{ 3, 4 };
	SimpleClass11{};
	/*	Also passing {arguments} to function or returning from it
	1)  SimpleClass func(SimpleClass param) {return {1};}
	2)	func({1,2}); */

	cout << "\nSimpleClass mass_c[3] = { 1, {}, {3,4} }; \n";
	SimpleClass11 mass_c[3] = { 1, {}, {3,4} };
}

//Constructor
SimpleClass11::SimpleClass11()
{
	cout << "Constructor SimpleClass11()" << endl;
	a = 1;
	b = 2;
	c = new int(0);
}

//Parametrised constructor
SimpleClass11::SimpleClass11(int A)
{
	cout << "Constructor SimpleClass11(" << A << ")" << endl;
	a = A;
	b = 2;
	c = new int(0);
}

//Parametrised constructor2
SimpleClass11::SimpleClass11(int A, int B)
{
	cout << "Constructor SimpleClass11(" << A << ", " << B << ")" << endl;
	a = A;
	b = 2;
	c = new int(0);
}

//Destructor
SimpleClass11::~SimpleClass11()
{
	if (c)
		delete(c);
}

void SimpleClass11::SomeMethod()
{
	a = 0;
	b = 0;
}