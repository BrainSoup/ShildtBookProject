#include <iostream>
#include "ColorText.h"
#include "Chapter13.h"

using namespace std;

#pragma region class_Point
//Some operators prohibited to overload: '.', '::', '.*', '?'

class Point {
	int x = 0, y = 0;
	char * tag = NULL;
public:
	Point(int X, int Y, const char * Tag = NULL);
	Point(const Point &copy);
	~Point();
	void Print() { cout << (tag ? tag : "") << "{" << x << ", " << y << "}" << endl; };
	void SetTag(const char *new_tag);
	
	//Class members operators overloads
	Point operator+(int op2);
	Point operator++();				// Prefix increment overload
	Point operator++(int unused);	// Postfix increment overload
	Point& operator=(const Point &other);
	int operator[](int index);

	//friend operators overloads
	//List of prohibited overloads in friend func: '=', '()', '[]', '->'
	friend Point operator+(int op1, Point op2);
	friend Point operator--(Point &op1);	//No reason to use non class member operator overloads
};

Point::Point(int X, int Y, const char *Tag)
{
	x = X;
	y = Y;
	CopyString(tag, Tag);
}

Point::Point(const Point &copy)
{
	x = copy.x;
	y = copy.y;
	CopyString(tag, copy.tag);
}

Point::~Point()
{
	if (tag)	
		delete[](tag);
}

void Point::SetTag(const char *new_tag)
{
	if (tag) 
		delete[](tag);
	CopyString(tag, new_tag); 
}

//Overload of binary operator
//Simple recomendation is to make operators behave like with base type,
//by this means operator + doesn't change operands, it returns the result
Point Point::operator+(int op2)
{
	cout << "Point::operator+(int op2)" << endl;
	Point tmp(x + op2, y + op2, tag);
	return tmp;
}

//Overload of unary operator
Point Point::operator++()
{
	cout << "Point::operator++()" << endl;
	x++;
	y++;
	return *this;
}

Point Point::operator++(int unused)	// (int unused) mark compiler diff between postfix and prefix form
{
	cout << "Point::operator++(int)" << endl;
	Point tmp(x, y, "tmp");
	x++;
	y++;
	return tmp;
}

//Must be implemented in objects that contains allocated memory or system resources
//cause by default operator= just copy all fields including pointers
Point& Point::operator=(const Point &other)
{
	cout << "Point::operator=(Point&)" << endl;
	this->x = other.x;
	this->y = other.y;
	SetTag(other.tag);

	return *this;
}

int Point::operator[](int index)
{
	if (index == 0)
		return x;
	if (index == 1)
		return y;
	return 0;
}

#pragma endregion

#pragma region Friends_of_Point

//friend function operatoroverload
//This type of overload come in handy if first operand is base type

//Overload of binary operator
Point operator+(int op1, Point op2)
{
	cout << "operator+(int op1, Point op2)" << endl;
	return op2 + op1;	//We already have overloaded op+, lets use Point::operator+(int op2)
}

//Overload of unary operator
Point operator--(Point &op1)	//In order to change operand value we need to use reference
{
	cout << "operator--(Point &op1)" << endl;
	op1.x--;
	op1.y--;
	return op1;
}

#pragma endregion

//Operators overload
void Chapter13Func() 
{
	PrintColorText("\nChapter 13. Operators overload\n");
	Point p(10, 10, "p"), p1(20, 20, "p1");
	p.Print();

	cout << "Point p1 = p + 5;" << endl;
	p1 = (p + 5);	//p doesn't changed
	p1.SetTag("p1");
	p.Print();
	p1.Print();

	//Postincrement
	cout << "\nbefore:";
	p.Print();
	cout << "(p++).Print(); \n(p++) instruction return:" << endl;
	(p++).Print();
	cout << "after:";
	p.Print();

	//Preincrement
	cout << "\nbefore:";
	p.Print();
	cout << "(++p).Print(); \n(++p) instruction return:" << endl;
	(++p).Print();
	cout << "after:";
	p.Print();

	//Friend binary operator overload
	cout << "\np1 = 12 + p;" << endl;
	p1 = (12 + p);
	p1.SetTag("p1");
	p1.Print();

	//Friend unary operator overload
	cout << "\n--p1;" << endl;
	--p1;
	p1.Print();

	//Operator=
	cout << "\np = p1;" << endl;
	p = p1;
	p.SetTag("p");
	p.Print();

	//Operator[]
	p.Print();
	cout << "\np = " << p[0] << ", "<< p[1] << endl;
}
