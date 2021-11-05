#include <iostream>

using namespace std;

void ConstPtrExample(int const* x, int* const y, const int* const z, const int* *const *const *w);
const int& ConstRefExample(const int &i, int &const j, const int &const k);

//TODO const function members example

void ConstExample()
{
	cout << endl << "Constants" << endl;

	//Pointers
	int a = 0, b = 0, c = 0, d = 0;
	ConstPtrExample(&a, &b, &c, 0);

	//References
	int i = 0, j = 0, k = 0;
	i = ConstRefExample(i, j, k);	//Also may use not const var to const param
	//ConstRefExample(i, j, k) = 1;	//Error return type (const int&) is not modifiable lvalue

	//Magic with const_cast<>
	// Write operation through the pointer, lvalue or pointer to data member resulting 
	// from a const_cast<> that casts away a const - qualifier may produce undefined behavior
	const int e = 1;
	int *pa = const_cast<int *>(&e);
	*pa = 2;	// Undefined behavior

	cout << endl;
}

/// <summary>
/// Instruction 'const' can be placed from any side of type and
/// Pointer '*' can align to any closest instructions without changing meaning.
/// This creates lots of confuses.
/// Always read such params from right to left to understand
/// Translate "*" as "pointer to"
/// </summary>
/// <param name="x">	(int const*)=(const int*) pointer to const int</param>
/// <param name="y">	(int* const) const pointer to int</param>
/// <param name="z">	(const int* const)=(int const * const) const pointer to const int</param>
/// <param name="w">	(const int **const *const *w) pointer to double const pointer to pointer to const int</param>

void ConstPtrExample(const int *x, int *const y, const int *const z, const int **const *const *w)
{
	//	Modify pointer
	x++;
	//y++;	//	Compile Error
	//z++;	//	Compile Error

	//	Modify pointer value
	//*x = 1;	//	Compile Error
	*y = 1;
	//*z = 1;	//	Compile Error

	// Assign int *const -> int*
	int* i_ptr = y;
	i_ptr++; // This pointer can be changed
	//i_ptr = x; i_ptr = z; i_ptr = w;	// Compile Error

	cout << "Pointer 'const int *' can be modified: x = " << x << ", (x++) =  " << x++ << endl;
	cout << "Pointer 'int* const' value can be modified: *y = " << *y << ", (*y)++ =  " << (*y)++ << endl;
	cout << "Pointer 'const int *const'  can't be modified." << endl;
}

/// <summary>
/// Next example show behavior of const referrence and referrence to const
/// As a summury const referrence is useless and work same as regular referrence
/// </summary>
/// <param name="i">	(int const&)=(const int&) reference to const int</param>
/// <param name="j">	(int& const) const reference to int</param>
/// <param name="k">	(const int& const)=(int const & const) const reference to const int</param>
/// <returns>	referrence to const int as return type prevents from using function in lvalue</returns>	
const int& ConstRefExample(const int& i, int &const j, const int &const k)
{
	//	References can't be modified, only their values
	//i++;	//	Compile Error
	j++;	
	//k++;	//	Compile Error

	// Assign int &const -> int&
	int &i_ptr = j;
	//i_ptr = i; i_ptr = k;	// Compile Error

	cout << "References 'const int& i' can't be modified" << endl;
	cout << "References 'const int& i' value can't be modified." << endl;
	return i;
}