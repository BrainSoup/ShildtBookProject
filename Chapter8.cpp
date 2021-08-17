#include <iostream>
#include "ColorText.h"

using namespace std;

int* PointerFunc(int* p);
int& ReferenceFunc(int& p);

void Chapter8Func()
{
    PrintColorText("\nChapter 8. References and functions");

    int p = 0;
    int p1 = 100;
    int* i_ptr = new int(10);

    //Execute pointer based func
    int new_p = *PointerFunc(&p);
    int *i_ptr1 = PointerFunc(i_ptr);
    cout << "PointerFunc results: " << new_p << ", " << *i_ptr1 << endl;

    p = 0;
    *i_ptr1 = 10;

    //Execute reference based func
    new_p = ReferenceFunc(p);
    i_ptr1 = &ReferenceFunc(*i_ptr);
    cout << "ReferenceFunc results: " << new_p << ", " << *i_ptr1 << endl;

    //Funcs returning references can be used as left operands
    p = 0;
    ReferenceFunc(p) = 11;
    cout << "Result 'ReferenceFunc(p) = 11;': p=" << p << endl;

    int& r = p;
    r++;
    cout << "r = " << r << endl;
    //Can't get pointer to int&, just to value referenced by int& 
    int* p_r = &r;
    cout << "int* p_r = &r; => p_r -> p " << p_r << " = " << &p << endl;

    //Reference of reference is not possible
    //int& r_1 = r; //r_1 refers to p

    //Array of reference is not allowed
    //int& r_1[5]; //error
    
    //Reference must be initializes in declaration
    //int& new; //error

    //Reference reinitialization is impossible
    r = p1; //Just copies a value of p1 to p

    delete i_ptr;
}

int* PointerFunc(int* p)
{
    *p += 10;
    return p;
}

int& ReferenceFunc(int& p)
{
    p += 10;
    return p;
}