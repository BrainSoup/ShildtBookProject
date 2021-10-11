#include <iostream>
#include "ColorText.h"
#include "Chapter17.h"

using namespace std;

#pragma region ExceptionClasses

class MyException
{
	int _exceptionCode;
	string _msg;
public:
	MyException(string msg, int code = 0)
	{
		_msg = msg;
		_exceptionCode = code;
	}

	string GetMsg() { return _msg; }
	int GetCode() { return _exceptionCode; }
};

class DerivedException : public MyException 
{
public:
	DerivedException(string msg, int code = 0) : MyException(msg, code) {};
};
#pragma endregion

//Base classes in catch statements will catch all derived classes exception
void DerivedExample()
{
	cout << "Derived exception class catching:" << endl;

	try {
		cout << "throw MyException(\"MyException\");" << endl;
		cout << "catch (DerivedException e)" << endl;
		cout << "catch (MyException e)\n->>" << endl;
		throw MyException("MyException");
	}
	catch (DerivedException e) {	//Derived don't catch base class exception
		cout << "catch (DerivedException e): " << e.GetMsg() << endl << endl;
	}
	catch (MyException e) {	//Base do catch base class exception
		cout << "catch (MyException e): " << e.GetMsg() << endl << endl;
	}

	try {
		cout << "throw DerivedException(\"DerivedException\");" << endl;
		cout << "catch (MyException e)" << endl;
		cout << "catch (DerivedException e)\n->>" << endl;
		throw DerivedException("DerivedException");
	}
	catch (MyException e) {	//Base do catch Derived class exception
		cout << "catch (MyException e): " << e.GetMsg() << endl << endl;
	}
	catch (DerivedException e) {
		cout << "catch (DerivedException e): " << e.GetMsg() << endl << endl;
	}
}

//catch(...) will catch all exceptions
void AllExceptionCatching(int ex)
{
	try{
		if (!ex)	throw NULL;
		if (ex == 1)	throw MyException("Some Exception");
		if (ex == 2)	throw "string";
	}
	catch (...) {
		cout << "catch (...): exception catched, ex=" << ex << endl;
	}
}

//throw(//..., ...//) specifies exceptions, that func can throw
//other exception types will terminate program
//Visual studio don't terminate program, this is unexpected behavior
void FuncRestrictions(int ex) throw (int, string)
{
	cout << "FuncRestrictions(" << ex << ")" << endl;
	if (ex==0) throw 10;
	if (ex==1) throw "string";
	if (ex>1) throw MyException("Ex > 1");
}

//throw ; statement in catch block rethrows catched exception
void RethrowExceptions()
{
	cout << "\nRethrow exception example:" << endl;
	try {
		try {
			throw DerivedException("DerivedException");
		}
		catch (DerivedException ex) {
			cout << "catch (DerivedException ex): exception catched; ex.Msg = " << ex.GetMsg() << endl;
			throw; 
		}
		catch (...) {	//This block won't catch exception, cause exception already catched, and this try-catch block is over
			cout << "catch (...): exception catched;" << endl;
		}
	}
	catch (DerivedException e){
		cout << "outer block catch (DerivedException e): exception catched; e.Msg = " << e.GetMsg() << endl;
	}

}

void Chapter17Func()
{
	PrintColorText("\nChapter 17. Exceptions\n");

	DerivedExample();

	AllExceptionCatching(1);
	AllExceptionCatching(0);

	cout << "\nFunction exception restrictions example:" << endl;
	try{
		int ex = 1;
		ex = 3;	// Program will be terminated (Visual Studio don't work as expected, so program will continue execution)
		FuncRestrictions(ex);
	}
	catch (...){
		cout << "FuncRestrictions exception catched." << endl;
	}

	RethrowExceptions();

	try {
		int *i = new int[32];	//new can throw exception
		int *j = new(nothrow) int[32];	//new(nothrow) can't throw exception, just return null on fail
	}
	catch (bad_alloc e){}	//catch exceptions from new instruction
}