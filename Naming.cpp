#include <iostream>
#include "ColorText.h"
#include "Naming.h"

using namespace std;

void NamingFunc()
{
	PrintColorText("\Naming in C++\n");

	//Statement is code before ';'
	cout << "\nStatements: \n"<< "int i=0;\ni++;" << endl;

	//Expression is operations with variables
	cout << "\nExpressions: \n" << "2+3;\nx+y*z/2+Sum();" << endl;

	//Identifier is name of variable, function, class, etc... 
	cout << "\nIdentifier: \n" << "int myVar; // myVar is identifier\n" << endl;

	//Declaration specifies name and type
	//A declaration introduces a name into a scope
	cout << "\nDeclarations: \n" << "extern int i; //declares i, but does not define it\n" << "void Foo(double d);" << endl;

	//Definition
	//A definition fully specifies an entity. 
	//Definitions are where the actual creation of the entity in memory takes place.
	//All definitions are also declarations, but not all declarations are definitions
	cout << "\nDefinition: \n" << "const int i = x + y;\n" << "void Foo(double d) {return;}" << endl;

	//Prototype
	//A prototype is just another name for a declaration of a function
	cout << "\nPrototype: \n" << "void Foo(int i);" << endl;

	//Implementation
	//An implementation is another name for a definition of a function
	cout << "\nImplementation: \n" << "void Foo(int i) {return;}" << endl;

	//Initialization
	//Initialization of a variable provides its initial value at the time of construction
	cout << "\nInitialization: \n" << 
		"int i(0); //Direct initialization\n" << 
		"double j=1.1; //Copy initialization" << endl;

	//l-value is variable that have address and can be assigned
	cout << "\nL-values: \n" << "int i = 0; // i is l-value\n" << "i=13;" << endl;

	//r-value is variable that don't have address and can't be assigned (literals and temp variables)
	cout << "\nR-values: \n" << "int i = 0; // 0 is r-value\n" << "cout<<x+y<<endl; //x+y r-value " << endl;

	//Parameters
	cout << "\nParameters: \n" << "void Foo(int i); //i is parameter" << endl;

	//Arguments
	cout << "\nArguments: \n" << "Foo(i); //i is argument" << endl;

}