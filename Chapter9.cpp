#include <iostream>
#include "Consts.h"
#include "ColorText.h"

using namespace std;

void StaticExample(int i);
int ComaExample();

//typedef Creates new name for type
typedef char symbol;

//extern: Use variables or functions from other files
//Makes compiler init variable but not declare a new one
extern int global_var;

//global static: visible only in declared file
static int global_var_2;

//Type specifiers
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
	cout << "Uninitialised static global var " << global_var_2 << endl;
	StaticExample(100);
	StaticExample(200);

	//register:
	register int reg = 1; //may be stored in register to speedup

	//coma
	int coma = ComaExample();
	cout << "ComaExample(); returns (return i, 13, i + 1, var;): " << coma << endl;

	//sizeof can be used with type or variable
	cout << "sizeof(int)= " << sizeof(int) << ", sizeof(i)= " << sizeof v << endl;

	//sizeof also works with massives
	int mass[10];
	cout << "sizeof int[10]= " << sizeof mass << endl;

	//enums
	//enums is named ints
	enum fruites { apple, banana, pear = 5, kiwi } fruit1, fruit2;
	fruit1 = apple;
	fruit2 = pear;
	fruites fruit3 = fruites(2);

	cout << "fruit1 : " << fruit1;
	cout << " fruit2 : " << fruit2;
	cout << " fruit3 : " << fruit3;

	cout << endl;
}

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

int global_var_1 = 101;