#include <iostream>

using namespace std;

class SimpleClass {
//private:
	int a, b;
public:
	int* c = 0;
	SimpleClass();
	SimpleClass(int a); //	for one param constructor compiler create implicit conversation from param type to class type
	SimpleClass(int a, int b);
	~SimpleClass();
	void SomeMethod();	//Not inline
	int Get_a() { return a; }	//inline cause declared in class declaration
}global_simpleClass;	//Constructors of global objects executes before main()

//Classes
void Chapter11Func()
{
	cout << endl << "Chapter 11. Classes" << endl;

	//Initialize new class
	cout << "SimpleClass c = SimpleClass(); \n";
	SimpleClass c = SimpleClass();

	cout << "SimpleClass *c_ptr = new SimpleClass(); \n";
	SimpleClass *c_ptr = new SimpleClass();
	delete c_ptr;

	cout << "SimpleClass c1(1) \nSimpleClass c1_1{2, 3}; \nSimpleClass c1_2;\n";
	cout << "static_cast<SimpleClass>(c1_2); \nnew SimpleClass(1, 2);" << endl;
	cout << "\n1) direct-initialization" << endl;
	SimpleClass c1(1);
	SimpleClass c1_1{ 2, 3 };
	SimpleClass c1_2;
	static_cast<SimpleClass>(c1_2);
	new SimpleClass(1, 2);
	(SimpleClass)1; // Only for 1 param constructor
	//Some other cases
	SimpleClass c1_3();	//No compile error, DO NOTHING, c1_3 not declared

	cout << "\n2) copy-initialization" << endl;
	cout << "SimpleClass c2 = 2; \nSimpleClass c2_1 = { 3, 4 }; \nSimpleClass c2_2 = SimpleClass{}" << endl;
	SimpleClass c2 = 2;	//	In this case compiler create implicit conversation from param type to class type
	SimpleClass c2_1 = { 3, 4 };
	SimpleClass c2_2 = SimpleClass{};
	//Also passing object to function or returning from it
	//Some other cases

	cout << "\n3) list-initialization" << endl;
	cout << "SimpleClass c3{ 1,2 }; \nSimpleClass c3_1 = {3}; \nSimpleClass{};" << endl;
	SimpleClass c3{ 1,2 };
	SimpleClass c3_1 = {3};
	SimpleClass{};
	/*	Also passing {arguments} to function or returning from it
	1)  SimpleClass func(SimpleClass param) {return {1};}
	2)	func({1,2}); */

	cout << "\nSimpleClass mass_c[3] = { 1, {}, {3,4} }; \n";
	SimpleClass mass_c[3] = { 1, {}, {3,4} };
}

//Constructor
SimpleClass::SimpleClass()
{
	cout << "Constructor SimpleClass()" << endl;
	a = 1;
	b = 2;
	c = new int(0);
}

//Parametrised constructor
SimpleClass::SimpleClass(int A)
{
	cout << "Constructor SimpleClass(" << A << ")" << endl;
	a = A;
	b = 2;
	c = new int(0);
}

//Parametrised constructor2
SimpleClass::SimpleClass(int A, int B)
{
	cout << "Constructor SimpleClass(" << A << ", " << B << ")" << endl;
	a = A;
	b = 2;
	c = new int(0);
	cout << "new " << c << endl;
}

//Destructor
SimpleClass::~SimpleClass()
{
	if (c)
	{
		cout << "~SimpleClass: delete c = "<< c << endl;
		delete(c);
	}
}

void SimpleClass::SomeMethod()
{
	a = 0;
	b = 0;
}