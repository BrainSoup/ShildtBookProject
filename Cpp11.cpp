#include <iostream>
#include <string>
#include "ColorText.h"
#include "Cpp11.h"

using namespace std;

namespace Cpp11
{
	#pragma region example types and funcs
	//1)constexpr func
	constexpr int Abs(int val)
	{
		return val < 0 ? -val : val;
	}

	// Compile-time computation of array length
	template<typename T, int N>
	constexpr int length(const T(&)[N])
	{
		return N;
	}

	//4)control of defaults: default and delete
	class X {
		X &operator=(const X &) = delete;	// Disallow copying
		X(const X &) = delete;
		//X &operator=(const X &) = default;	// default copy semantics
		//X(const X &) = default;
	};

	//5)control of defaults: move and copy
	//Strongly recommended that if you declare one of these five function, you explicitly declare all
	class Y {
		int *p;
	public:
		Y(int *pp) : p{ pp } {}

		//Defining of deleted constructor make other operation not implicitly generated
		//Y(const Y &val) = delete;
		//Y(Y &&h) = delete;
		//------------------

		//Example of working class
		//~Y() { delete p; }

		//// transfer ownership
		//Y(Y &&h) : p{ h.p } 
		//	{ h.p = nullptr; }
		//Y &operator=(Y && val)
		//	{ delete p; p = val.p; val.p = nullptr; return *this; }

		////copy
		//Y(const Y & val)
		//	{ p = new int(*val.p); }
		//Y &operator=(const Y & val)
		//	{ delete p; p = new int(*val.p); return *this; }
	};

	Y GetY()
	{
		return Y(new int(2));
	}

	//8)Class for initializer list
	class Point
	{
		float _x = 0, _y = 0, _z = 0;
	public:
		Point(initializer_list<float> list)
		{
			int count = list.size();
			cout << "Initializer list ctor, " << count << " elements" << endl;
			const float *p = list.begin();
			if (count > 0)	_x = *p;
			if (count > 1)	_y = *(p + 1);
			if (count > 2)	_z = *(p + 2);
		}

		void Print()
		{
			cout << "x=" << _x << ", y=" << _y << ", z=" << _z << endl;
		}
	};

	//9)Delegating constructors
	class Z {
		int _a;
	public:
		Z(int x) 
		{ 
			cout << "Z(int x) " << endl;
			if (0 < x && x <= 100) _a = x; 
			else throw (x); 
		}
		
		Z() : Z{ 42 }				//Delegating constructor with literal
		{ cout << "Z()" << endl; }				
		
		Z(string s) : Z{ stoi(s) }	//Delegating constructor with expression
		{ cout << "Z(string s)" << endl; }

		void Print()
		{
			cout << "a=" << _a << endl;
		}
	};

	//10)In-class member initializers
	class A {
		//------------------
		int _a = 7;
		string str = "Some string";
		//---- This is equivalent to :
		//int _a;
		//A() : _a(7) {}
		//------------------
	public:
		A() = default;

		A(int i)	//If a member is initialized by both an in-class initializer and a constructor, only the constructor's initialization is done
		{
			str = "Other string";
		}

		void Print()
		{
			cout << "_a=" << _a << ", str=" << str << endl;
		}
	};

	//13)Suffix return type syntax
	//Usefull with templates
	auto AutoFunc(string a, string b)
	{
		return a + b;
	}

	//14)Uniform initialization syntax and semantics
	class B {
		int _a, _b;
	public:
		B(int a, int b) : _a{ a }, _b{b} {}
	};

	//15)Rvalue references
	int RvalueExample() { return 0; };

	//17)Lambdas
	int Operation(int op1, int op2, int ((*f)(int op1, int op2)))
	{
		return (*f)(op1, op2);
	}

	//18)noexcept -- preventing exception propagation
	// All next functions definitions are same
	//void NoExcept() throw()
	//void NoExcept() noexcept
	void NoExceptions() noexcept(true)
	{
		throw 1;
	}

	// All next functions definitions are same
	//void AllExceptions() throw(...)
	void AllExceptions() noexcept(false)
	{
		throw 1;
	}

	//20)Override controls: override
	struct B1 {
		virtual void f();
		virtual void g() const;
		virtual void h(char);
		void k();	// not virtual
	};

	struct D1 : B1 {
		void f();	// overrides B1::f()
		void g();	// doesn't override B1::g() (wrong type)
		virtual void h(char);	// overrides B1::h()
		void k();	// doesn't override B1::k() (B1::k() is not virtual)
	};

	//With new keyword override we get a compile error on method that can't override
	struct D1Override : B1 {
		void f() override;	// OK: overrides B1::f()
		//void g() override;	// compile error: wrong type
		virtual void h(char);	// overrides B1::h(); likely warning
		//void k() override;	// compile error: B1::k() is not virtual
	};

	//21)Override controls: final
	struct B2 {
		virtual void f() const final;	// do not override
		virtual void g();
	};

	struct D2 : B2 {
		//void f() const; 	//compile error: D2::f attempts to override final B2::f
		void g();			// OK
	};
	#pragma endregion

	void Сpp11Func()
	{
		PrintColorText("\nStandart C++ 11\n");

		cout << "\n1)Constexpr:" << endl;
		//Added new keyword 'constexpr' to signal that variable or func is cpmpile time constant 
		//As example massive require compile constant as lenth, so other way we get compile error
		int mass1[Abs(-10)];	//constexpr func
		cout << "int mass1[Abs(-10)]; mass length is " << length(mass1) << endl;

		constexpr float f = 8.1f;	//before c++11 in const expressions only enums and ints may take place
		int mass2[(int)8.1f];	//constexpr variable
		cout << "int mass2[(int)8.1f]; mass length is " << length(mass2) << endl;

		int someValue = 1;
		int val = Abs(someValue);	//constexpr functions can be used as regular for not constexpr results

		cout << "\n2)auto keyword:" << endl;
		//auto define type, same as var in c#
		auto myVar = 12.0;

		cout << "\n3)Range statement for:" << endl;	//TODO define type with begin() and end() as an example
		//A range for statement allows you to iterate through a "range", which is anything you can iterate through like an STL-sequence defined by a begin() and end()
		int mass[] = { 1,2,3,4,5,6,7,8,9 };
		cout << "for (auto &x : mass)" << endl;
		for (auto &x : mass)	//iterate with ability to modify elements
		{
			cout << x << " ";
			x++;
		}
		cout << "\nfor (auto x : mass)" << endl;
		for (auto x : mass)		//iterate all elements
			cout << x << " ";
		cout << "for (auto x : \"Some string\")" << endl;
		for (auto x : "Some string")	//iterate all elements
			cout << x << " ";

		cout << "\n4)control of defaults: default and delete:" << endl;
		X x1();
		//X x2(x1);	//Copy constructor
		//x1 = x2;	// = operator

		cout << "\n5)Control of defaults: move and copy" << endl;
		//By default, a class has 5 operations :
		//copy assignment, copy constructor
		//move assignment, move constructor
		//destructor
		//If any of those defined explicitly: no move is generated by default, copy is generated by default ??? not work
		Y y(new int(1));
		Y y1(y);		//copy constructor
		Y y2(GetY());	//move constructor
		Y y3 = y;		//copy operator = (l-value)
		Y y4 = GetY();	//move operator = (r-value)

		cout << "\n6)enum class: scoped and strongly typed enums" << endl;
		//conventional enums and enum class diffs:
		//1)conventional enums implicitly convert to int
		//2)conventional enums export their enumerators to the surrounding scope
		//3)the underlying type of an enum cannot be specified 
		enum class TrafficLight { red, yellow, green };
		enum class Color : char { red = 'r', blue = 'b' };	// with specified type

		TrafficLight a = TrafficLight::yellow;
		Color b = (Color)'b';	//explicit conversation is allowed
		cout << "Color b = (Color)'b'; b = " << (char)b << endl;
		//TrafficLight c = 2;				// error: no int->Color conversion
		//int a1 = TrafficLight::green;		// error: can't make TrafficLight->int conversion
		//a1 = green;						// error: green not in scope

		cout << "\n7)decltype -- the type of an expression" << endl;
		//Declares new type name for expression result type
		//Use decltype if you need a type for something that is not a variable, such as a return type
		//Other way autois better choice
		typedef decltype(GetY()) decltypeY;
		decltypeY newY();

		cout << "\n8)Initializer lists" << endl;
		cout << "\nPoint point({ 10, 20.0, 30.0f });" << endl;
		Point point({ 10, 20.0, 30.0f });
		point.Print();
		cout << "\nPoint point({  });" << endl;
		Point point1 = {};
		point1.Print();
		cout << "\npoint = { 1, 2 };" << endl;
		point = { 1, 2 };
		point.Print();
		//also can be used for basic types
		int i1{ 1 }, i2 = {2};
		
		cout << "\n9)Delegating constructors" << endl;
		// Syntax for execution of other constructor
		cout << "z1:" << endl;
		//Z z1(); not work causeits same as func declaration
		Z z1;
		cout << "z2:" << endl;
		Z z2("43");

		cout << "\n10)In-class member initializers" << endl;
		A a1, a2(2);
		cout << "\nA a1 => ";
		a1.Print();
		cout << "\nA a2(2) => ";
		a2.Print();

		cout << "\n11)long long -- a longer integer" << endl;
		long long l = 9223372036854775807LL;

		cout << "\n12)nullptr -- a null pointer literal" << endl;
		//nullptr is a literal denoting the null pointer; it is not an integer
		char *p = nullptr;	//applied to any pointer type

		//Fix ambitious calls (as null is 0, void f(char *) can't be called with null)
		//void f(int);
		//void f(char *);
		//f(0);         		// call f(int)
		//f(nullptr);   		// call f(char*)

		//void g(int);
		//g(nullptr);		// error: nullptr is not an int
		//int i = nullptr;	// error nullptr is not an int

		cout << "\n13)Suffix return type syntax" << endl;
		//auto can be used as return type

		cout << "\n14)Uniform initialization syntax and semantics" << endl;
		//It can be hard to remember the rules for initialization and to choose the best way.
		//The C++11 solution is to allow{} - initializer lists for all initialization
		B b1 = B{ 1, 2 };
		B b2 = { 1, 2 }; 	// the = is optional
		B b3{ 1, 2 };
		B *pb = new B{ 1, 2 };

		cout << "\n15)Rvalue references" << endl;
		int i = 0;
		int &r1 = i;					// bind r1 to a (an lvalue)
		//int &r2 = RvalueExample();	// error: f() is an rvalue; can't bind
		
		int &&rr1 = RvalueExample();	// fine: bind rr1 to temporary
		//int &&rr2 = a;				// error: bind a is an lvalue

		cout << "\n16)Raw string literals" << endl;
		cout<<R"(Raw\r string\n example)"<<endl;	//Raw string \ is just a character

		cout << "\n17)Lambdas" << endl;
		// [] prefix: vars from local scope to capture
		// [] - capture nothing
		// [&] - capture all by references
		// [=] - capture all by value
		// [&Var]/[=Var] - capture local variable 'Var'
		int op1 = 10, op2 = 5, res = 0;
		int (*lambda)(int op1, int op2) = [](int o1, int o2) { return o1 + o2; };	//Simple lambda
		res = Operation(op1, op2, lambda);

		cout << "\n18)noexcept -- preventing exception propagation" << endl;
		//If a function cannot throw an exception or if the program isn't written
		//to handle exceptions thrown by a function, that function can be declared noexcept
		//Program terminated if func with noexcept throws exception
		//noexcept(const expr), if const expr=true func can't throw
		try
		{
			AllExceptions();
			//NoExceptions();	//Will call terminate
		}
		catch (...)
		{
			cout << "Exception catched, continue program. Typeof exception: " << endl;
		}

		cout << "\n19)alignment" << endl;
		alignas(int) char c[100] = {1,2,3};
		constexpr int n = alignof(int);
		cout << "\nalign of int = " << n << endl;

		cout << "\nstruct alignas(32) alignedStruct {};"<< endl;
		struct alignas(32) alignedStruct {};
		alignedStruct aMass[3] = {};
		cout << hex << showbase << "&aMass[0]: " << &aMass[0] << '\n' << "&aMass[1]: " << &aMass[1] <<"\n" << "&aMass[2]: " << &aMass[2] << endl;

		cout << "\n20)Override controls: override" << endl;
		//Using explicit override helps find problems at compile time

		cout << "\n21)Override controls: final" << endl;
		//Sometimes, a programmer wants to prevent a virtual function from being overridden. This can be achieved by adding the specifier final

		cout << "22)Explicit conversion operators" << endl;
		//Conversion operators allowed to be explicit
	}
}