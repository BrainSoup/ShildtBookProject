#include <iostream>
#include "Chapter12.h"
#include "ColorText.h"
using namespace std;

//TODO virtual functions from constructor

#pragma region ExampleFunctions

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
	SimpleClass12 c5(5);	//Destructor will be called for c4
	return c5;
}

//Copy constructor example
FriendClass CopyConstructorTest(FriendClass c)
{
	cout << "\nCopyConstructorTest();\nFriendClass c1; //Basic initialisation" << endl;
	FriendClass c1;		//Constructor
	cout << "\nc1 = c; //Copy object fields, constructor not called" << endl;
	c1 = c;				//Any Constructor not called
	cout << "\nFriendClass c2 = c; //Explicit initialisation" << endl;
	FriendClass c2 = c;	//Explicit initialisation (Copy Constructor)
	cout << "\nreturn c2;" << endl;
	return c2;			//Return (No Constructor) 
}

//Copy constructor example #2
FriendClass CopyConstructorTest2()
{
	cout << "\nCopyConstructorTest2();\nreturn FriendClass();" << endl;
	return FriendClass();			//Return (No Constructor) 
}

#pragma endregion

//Subchapter functions made to create separate scopes to all subchapters
//in order to see destructors calls
#pragma region SubchaptersFuncs

void FriendKeyword()
{
	PrintColorText("\nFriend functions and methods:", TextColor::BlueText);
	SimpleClass12 c1 = SimpleClass12(1, 2, 3, "c1");
	Print(c1);

	FriendClass fc;
	fc.SomeMethod(&c1);
}

void ObjectCopying()
{
	PrintColorText("\nObject copying:", TextColor::BlueText);
	SimpleClass12 c2(2, 1, 1, "c2"), c3(3, 0, 0, "c3");
	Print(c2); Print(c3);
	c2 = c3;	//By default copy all fields from c1 to c2
	cout << "c2 = c3; Print(c2); ";
	Print(c2);
	cout << "c2.c == c3.c;" << " c2.c = " << c2.c << " c3.c = " << c3.c << endl; //Pointers refers to same memory
	c2.c = 0; //Fix double memory release
	c2.name = 0; //Fix double memory release
}

void SendReturnObjects()
{
	PrintColorText("\nSending and returning objects by value", TextColor::BlueText);
	SimpleClass12 c4 = SimpleClass12(4);
	ObjValueParam(c4);						// Destructor will be called for c4 and for param in ObjValueParam() with same fields
	SimpleClass12 c6 = ObjValueReturn();	// Destructor will be called for c6 and c5 wich have copied fields
	c6.SetA(6);	//To show number in destructor
}

void CopyConstructor()
{
	PrintColorText("\nCopy Constructor\n", TextColor::BlueText);
	cout << "FriendClass fc1;" << endl;
	FriendClass fc1;				//Constructor
	cout << "\nCopyConstructorTest(fc1); //Send object by value to param" << endl;
	FriendClass fc2 =				//Explicit initialisation (Copy Constructor)
		CopyConstructorTest(fc1);	//Parameter initialisation (Copy Constructor)

	//return statement by itself don't create temp object
	CopyConstructorTest2();	//No copy construction call
}

#pragma endregion

//Classes(Advanced)
void Chapter12Func()
{
	PrintColorText("\nChapter 12. Classes (Advanced)");

	//Friend example
	FriendKeyword();

	//Object copying
	ObjectCopying();

	//Sending and returning objects by value
	SendReturnObjects();
	
	//Copy Constructor
	CopyConstructor();
}

#pragma region SimpleClass12

SimpleClass12::SimpleClass12(int a)
{
	cout << "Constructor " << a << " (int a)" << endl;
	pr_a = a;
}

SimpleClass12::SimpleClass12(int a, int b, int c, const char *name_)
{

	cout << "Constructor " << (name_ ? name_ : "null") << " (int a, int b, int c)" << endl;
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

//TODO fix memory leak
const char *SimpleClass12::ToString()
{
	const size_t size = 40;
	char *result = new char[size];
	snprintf(result, size, "( pr_a = %d, pr_b = %d, c = %d)", pr_a, pr_b, *c);
	return result;
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

#pragma endregion SimpleClass12 methods

void FriendClass::SomeMethod(SimpleClass12 *c)
{
	cout << "FriendClass::SomeMethod(SimpleClass12* c), c->pr_a = " << c->pr_a << ", c->pr_b = " << c->pr_b << endl;
}
