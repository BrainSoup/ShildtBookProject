#include <iostream>
#include "Consts.h"
#include "ColorText.h"

using namespace std;

#pragma region ExampleFunctions

void StaticExample(int i)
{
	//This command works only at first entry
	static int k = i; //Initialise only once
	k++;
	cout << "static int k = " << k << ", i =  " << i << endl;
}

int ComaExample()
{
	int i = 1;
	int var = (i = 10, i += 110, i + 1);//Coma in expression always returns right part but execute all
	cout << "int i = 1;" << endl << "int var = (i = 10, i += 110, i + 1);" << endl;
	cout << "i = " << i << ", var = " << var << endl;
	return i, 13, i + 1, var;
}
#pragma endregion

//typedef Creates new name for type
typedef char symbol;

//extern: Use variables or functions from other files
//Makes compiler init variable but not declare a new one
//global_var declared in ShildtBook.cpp
extern int global_var;

//global static: visible only in declared file
static int global_var_2;

void Chapter9Func()
{
	PrintColorText("\nChapter 9. Var modifiers and Enums");

	ConstExample();

	//volatile
	//Disable compile optimisation of var
	volatile int v = 0;
	
	//extern: Use of variables lower in file
	extern int global_var_1;
	global_var_1++;
	cout << "extern int global_var_1 = " << global_var_1 << endl;

	//static: 
	cout << "\nUninitialised static global var " << global_var_2 << endl;
	StaticExample(100);
	StaticExample(200);

	//register:
	register int reg = 1; //may be stored in register to speedup

	//coma
	cout << "\nComaExample():" << endl;
	int coma = ComaExample();
	cout << "returns (return i, 13, i + 1, var;): " << coma << endl;

	//sizeof can be used with type or variable
	cout << "\nsizeof(int)= " << sizeof(int) << ", sizeof(i)= " << sizeof v << endl;

	//sizeof also works with massives
	int mass[10];
	cout << "\nsizeof int[10]= " << sizeof mass << endl;

	//enums
	//enums is named ints
	enum fruites { apple, banana, pear = 5, kiwi } fruit1, fruit2;
	fruit1 = {apple};
	fruit2 = pear;
	fruites fruit3 = fruites(2);
	fruites fruit4 = kiwi;

	cout << "\nfruit1 = apple : " << fruit1 << ";";
	cout << " fruit2 = pear: " << fruit2 << ";";
	cout << " fruit3 = fruites(2): " << fruit3 << ";";
	cout << " fruit3 = kiwi: " << fruit3 << ";";

	cout << endl;
}

int global_var_1 = 101;