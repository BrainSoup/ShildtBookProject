//Chapter 3
#include <iostream>
#include <string>

using namespace std;

int global_i;

void Chapter3Func()
{
    cout << endl << "Chapter 3. Base Types" << endl;

    char c;

    wchar_t wc;
    int i;
    float f;
    double d;
    bool b;
    void* v = &i;
    int* p_i = &i;
    //global variables initialized by default with 0
    cout << "globel_i = " << global_i << endl;
    //local not initialized by default
    cout << "i = " << int(*p_i) << endl;
    
    //also there is type modifiers:
    //signed, unsigned, long, short

    signed char c1;
    unsigned char c2;

    signed short int i1;
    unsigned long int i2;
    unsigned i3; //this is also int
    long i4;

    long double d1;
    string s;

    //Pointer assigns in initialisation to every varioable separatly
    int* i5, i6, *i7;
    cout << "type of (int* i5, i6, *i7;) i5 = " << typeid(i5).name() << ", i6 = " << typeid(i6).name() << ", i7 = " << typeid(i7).name() << endl;

    //Using operands of diff type compiler casts lower type to wider if possible
    cout << "type of c = " << typeid(i + f).name() << endl;
}