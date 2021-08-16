#include <iostream>

using namespace std;

int ConstPtrExample(const int* i);
const int& ConstRefExample(const int& i); //const return ref type prevents from using function in lvalue

void ConstExample()
{
	cout << endl << "Constants" << endl;

	//const
	const int i = 0;
	int j = ConstPtrExample(&i);
	int i1 = 0;
	i1 = ConstRefExample(i1);	//Also may use not const var to const param
	//ConstRefExample(i1) = 1;	//Error (const int&) is not modifiable lvalue

	cout << endl;
}

int ConstPtrExample(const int* i)
{
	//int* i_ptr = i; // compile error
	//(*i)++;	// compile error
	i++;		// Ok
	cout << "Pointer 'const int* i' can be modified: (i) = " << i << ", (i++) =  " << i++ << endl;
	cout << "Pointers 'const int* i' value can't be modified." << endl;
	return *i;
}

const int& ConstRefExample(const int& i)
{
	//int* i_ptr = i; // compile error
	//(*i)++;	// compile error
	//i++;		// compile error
	cout << "References 'const int& i' can't be modified" << endl;
	cout << "References 'const int& i' value can't be modified." << endl;
	return i;
}