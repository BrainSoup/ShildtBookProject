#include <iostream>
#include <typeinfo>
#include "ColorText.h"
#include "Chapter19.h"

using namespace std;

#pragma region Classes

class Base {
	//virtual void F() {}
};

class Derived1 : public Base
{
	virtual void F() {}
};

class Derived2: public Derived1 {};

#pragma endregion

#pragma region Example_functions

void TypeInfoExample()
{
	cout << "typeinfo examples:" << endl;

	Base b1;
	Derived1 d1;
	Derived2 d2;
	Base *p_b2 = &d1, *p_b3 = &d2;

	//Base is not polymorph class, typeid don't show real class
	cout << "b1 = " << typeid(b1).name() << endl;
	cout << "b2 = " << typeid(*p_b2).name() << endl;
	cout << "b3 = " << typeid(*p_b3).name() << endl;

	Derived1 *p_d1 = &d1, *p_d2 = &d2;

	//Derived1 is polymorph class, typeid show real class
	cout << "b4 = " << typeid(*p_d1).name() << endl;
	cout << "b5 = " << typeid(*p_d2).name() << endl;

	//Also works the same for template classes
}

void CastsExamples()
{
	cout << "\nDynamic cast:" << endl;
	//dynamic_cast used for type conversations of objects, works also with not polymorph classes

	Base b;
	Derived1 d;

	//dynamic_cast with pointers
	Base *b1 = dynamic_cast<Base *>(&d);	//in case of failure return null
	cout << "Cast Derived1 to Base using pointers is " << (b1 == 0 ? "failed" : "successful") << endl;

	//dynamic_cast with references
	Derived1 &d1 = d;
	try
	{
		cout << "Cast Derived1 to Base using references is ";
		Base &b2 = dynamic_cast<Base &>(d);	//in case of failure throw exception
		cout << "successful" << endl;
	}
	catch (bad_cast e)
	{
		cout << "failed\n" << e.what() << endl;
	}

	cout << "\nConst cast:" << endl;
	//const_cast used for add/remove const modifier

	int i1 = 0;
	const int *i=&i1;
	//*i = 100;	//Not allowed due to const modifier

	cout << "i=" << *i << " before const_cast" << endl;
	int *j = const_cast<int *>(i);
	*j = 100;
	cout << "i=" << *i << " after const_cast\n" << endl;

	cout << "Same operation using explicit cast" << endl;
	int *z = (int *)i;
	*z = 1001;
	cout << "i=" << *i << " after explicit cast" << endl;

	cout << "\nStatic cast:" << endl;
	//static_cast used for not polymorph type conversations
	float f = 13.9f;
	i1 = static_cast<int>(f);
	cout << "static_cast from float 13.9f to int, result: " << i1 << endl;
}
#pragma endregion

void Chapter19Func()
{
	PrintColorText("\nChapter 17. Typeinfo and dynamic type conversation\n");

	TypeInfoExample();
	CastsExamples();
}