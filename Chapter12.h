#pragma once
void Chapter12Func();

#include <iostream>
//using namespace std; 
//TODO https://docs.microsoft.com/ru-ru/cpp/cpp/header-files-cpp?view=msvc-160 header files recomendations 

class SimpleClass12;	//TODO explain this

//Friend class
class FriendClass {
public:
	void SomeMethod(SimpleClass12 *c);
	FriendClass() { std::cout << "FriendClass Constructor" << std::endl; };
	FriendClass(const FriendClass &copy) { std::cout << "FriendClass Copy Constructor" << std::endl; };
	~FriendClass() { std::cout << "FriendClass Destructor" << std::endl; };
};

class SimpleClass12 {
	int pr_a = 0, pr_b = 0;
public:
	int *c = 0;
	char *name = 0;
	SimpleClass12(int a);
	SimpleClass12(int a, int b, int c, const char *name);
	~SimpleClass12();
	void SetA(int a) { pr_a = a; };
	const char *ToString();
	friend void Print(SimpleClass12 &c);
	friend void FriendClass::SomeMethod(SimpleClass12 *c);
	friend int Sum(SimpleClass12 *c);
};