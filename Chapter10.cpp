#include <iostream>
#include <bitset>

using namespace std;

//simple struct
struct Point {
	int x, y;
} point1, point2;

//BitField struct
struct BitField {
	char some_char;		//Can contain normal members
	unsigned short x1 : 1;	//Byte fields "type var : bytes;"
	unsigned short x2 : 1;
	unsigned short x3 : 2;
	//unsigned short[10] x4 : 2; // compile error
};

//Union 
union MyUnion {	//Same memory for all members
	char chars[2];
	short int integer;
};


void OutputPoint(const char* str, Point& p);
Point* StructPointers(Point* p);

//Structs
void Chapter10Func()
{
	cout << endl << "--< Chapter 10. Structs and Unions >--" << endl;

	OutputPoint("(Global, not initialized) cout << point1 : ", point1);

	Point point;
	OutputPoint("(Local, not initialized) cout << point : ", point);

	point.x = 100;
	point.y = 120;
	OutputPoint("(Local, initialized) cout << point : ", point);

	Point* new_point = StructPointers(&point);
	cout << "Same object as putted in func StructPointers :" << new_point << " " << &point << endl;

	BitField bf;
	cout << "Size of ByteField: " << sizeof(BitField) << endl;
	bf.x1 = 1;
	bf.x2 = 0;
	bf.x3 = 127; // no check for overflow
	//unsigned short* s = &bf.x1; //compile error

	cout << "BitField: " << bf.x1 << " " << bf.x2 << " " << bf.x3 << endl;

	MyUnion u;
	u.integer = 0;
	u.chars[1] = 'c';

	cout << "Union (u.integer = 0; u.chars[0] = 'c';)" << endl << "u.integer : " << u.integer << endl;

	//Anonymouse union
	union {
		char chars[2];
		int integer;
	};
	cout << "Anonymouse union: " << integer << ", " << chars[0] << endl; //not initialized
	integer = (((int)'c') << 8) + 'z';
	cout << "'integer = ('c' << 8) + 'z';' chars : " << chars[0] << ", " << chars[1] << endl;
}

void OutputPoint(const char* str, Point& p)
{
	cout << str << p.x << " " << p.y << endl;
}

Point* StructPointers(Point* p)
{
	cout << p->x << " " << p->y << endl;
	return p;
}