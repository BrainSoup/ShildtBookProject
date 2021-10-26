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
	cout << "\nDeclarations: \n" << "int i;\n" << "void Foo(double d);" << endl;

	//Definition
	cout << "\nDefinition: \n" << "const int i = x + y;\n" << "void Foo(double d) {return;}" << endl;

	//Initialization
	cout << "\nInitialization: \n" << "int i=0;\n" << "double j=1.1;" << endl;

	//l-value is variable that have address and can be assigned
	cout << "\nL-values: \n" << "int i = 0; // i is l-value\n" << "i=13;" << endl;

	//r-value is variable that don't have address and can't be assigned (literals and temp variables)
	cout << "\nR-values: \n" << "int i = 0; // 0 is r-value\n" << "cout<<x+y<<endl; //x+y r-value " << endl;

	//Parameters
	cout << "\nParameters: \n" << "void Foo(int i); //i is parameter" << endl;

	//Arguments
	cout << "\nArguments: \n" << "Foo(i); //i is argument" << endl;

}