#include <iostream>
#include "ColorText.h"

class SimpleClass12 {
	//private:
	int a, b;
public:
	int* c = 0;
	SimpleClass12();
	SimpleClass12(int a);
	~SimpleClass12();
	void SomeMethod();//Not inline
	int Get_a() { return a; }//inline
};

//Classes
void Chapter12Func()
{
	//Initialize new class
	SimpleClass12 c1 = SimpleClass12();
	SimpleClass12* c2 = new SimpleClass12();
	SimpleClass12 c3(), c5(1);
	SimpleClass12 c4 = 4;//Only if available 1 param constructor
	SimpleClass12 mass_c[3] = { 1,2,3 };//Only if available 1 param constructor

}

//Constructor
//Constructors of global objects executes before main()
SimpleClass12::SimpleClass12()
{
	a = 1;
	b = 2;
	c = new int(0);
}

//Parametrised constructor
SimpleClass12::SimpleClass12(int A)
{
	a = A;
	b = 2;
	c = new int(0);
}

//Destructor
SimpleClass12::~SimpleClass12()
{
	if (c)
		delete(c);
}

void SimpleClass12::SomeMethod()
{
	a = 0;
	b = 0;
}