#include <iostream>
#include "ColorText.h"
using namespace std;

//TODO virtual functions from constructor

class SimpleClass12;	//TODO explain this

//Friend class
class FriendClass {
public:
	void SomeMethod(SimpleClass12 *c);
	FriendClass() { cout << "FriendClass Constructor" << endl; };
	FriendClass(const FriendClass & copy) { cout << "FriendClass Copy Constructor" << endl; };
	~FriendClass() { cout << "FriendClass Destructor" << endl; };
};

class SimpleClass12 {
	int pr_a = 0, pr_b = 0;
public:
	int* c = 0;
	char * name = 0;
	SimpleClass12(int a);
	SimpleClass12(int a, int b, int c, const char * name);
	~SimpleClass12();
	const char *ToString();
	friend void Print(SimpleClass12 &c);
	friend void FriendClass::SomeMethod(SimpleClass12* c);
	friend int Sum(SimpleClass12* c);
};

//Friend function
void Print(SimpleClass12 &c)
{
	printf("%s = ( pr_a = %d, pr_b = %d, c = %d)\n", c.name ? c.name : "null", c.pr_a, c.pr_b, c.c ? *(c.c) : 0);
}

//Object params by value Example
void ObjValueParam(SimpleClass12 c)	//Destructor will be called for param c
{
	cout << "ObjValueParam()" << endl;
}

//Object params by value Example
SimpleClass12 ObjValueReturn()
{
	cout << "ObjValueReturn()" << endl;
	SimpleClass12 c4(4);	//Destructor will be called for c4
	return c4;
}

//Copy constructor example
FriendClass CopyConstructorTest(FriendClass c)
{
	cout << "CopyConstructorTest()" << endl;
	FriendClass c1;		//Constructor
	cout << 1 << endl;
	c1 = c;				//Any Constructor not called
	cout << 2 << endl;
	FriendClass c2 = c;	//Explicit initialisation (Copy Constructor)
	cout << 3 << endl;
						//TODO Why return don't execute Copy Constructor?
	return c2;			//Return (No Constructor) 
}

//Classes
void Chapter12Func()
{
	PrintColorText("\nChapter 12. Classes (Advanced)");

	//Friend example
	cout << "Friend functions and methods:" << endl;
	SimpleClass12 c1 = SimpleClass12(1, 2, 3, "c1");
	Print(c1);

	FriendClass fc;
	fc.SomeMethod(&c1);

	//Object copying
	cout <<"\nObject copying:"<< endl;
	SimpleClass12 c2(2, 1, 1, "c2");
	Print(c1); Print(c2);
	//cout << "c1 = " << (c1.Print(), "; c2 = ") << (c2.Print(),"") << endl;
	c2 = c1;	//By default copy all fields from c1 to c2
	cout << "c2 = c1;";
	Print(c2);
	cout << "c2.c == c1.c;" << " c2.c = " << c2.c << " c1.c = " << c1.c << endl;
	c2.c = 0; //Fix double memory release
	c2.name = 0; //Fix double memory release

	//Sending and returning objects by value
	cout << "\nSending and returning objects by value" << endl;
	SimpleClass12 c3 = SimpleClass12(3);
	ObjValueParam(c3);						// Destructor will be called for c3 and for param in ObjValueParam() with same fields
	SimpleClass12 c5 = ObjValueReturn();	// Destructor will be called for c5 and c4 wich have copied fields
	
	//Copy Constructor
	cout << "\nCopy Constructor" << endl;
	FriendClass fc1;				//Constructor
	FriendClass fc2 =				//Explicit initialisation (Copy Constructor)
		CopyConstructorTest(fc1);	//Parameter initialisation (Copy Constructor)

}

SimpleClass12::SimpleClass12(int a)
{
	pr_a = a;
}

//TODO fix memory leak
const char *SimpleClass12::ToString()
{
	const size_t size = 40;
	char *result = new char[size];
	snprintf(result, size, "( pr_a = %d, pr_b = %d, c = %d)", pr_a, pr_b, *c);
	return result;
}

SimpleClass12::SimpleClass12(int a, int b, int c, const char * name_)
{

	cout << "Constructor " << (name_ ? name_ : "null" )<< " (int a, int b, int c)" << endl;
	pr_a = a;
	pr_b = b;
	this->c = new int(c);
	if (name_)
	{
		size_t size = strlen(name_) + 1;
		name = new char[size];
		strcpy_s(name, size, name_);
	}
}

SimpleClass12::~SimpleClass12()
{
	cout << "Destructor() " << pr_a << " ";
	if (name)
	{
		cout << name << endl;
		delete[](name);
	}
	else
		cout << endl;
	if (c)
		delete(c);
}

void FriendClass::SomeMethod(SimpleClass12* c)
{
	cout << "FriendClass::SomeMethod(SimpleClass12* c), c->pr_a = " << c->pr_a << ", c->pr_b = " << c->pr_b << endl;
}