#include <iostream>
#include "ColorText.h"

using namespace std;

int* PointerFunc(int* p);
int &ReferenceFunc(int& p);
int &ReferenceFunc(const int &p);

void Chapter8Func()
{
    PrintColorText("\nChapter 8. References and functions");

    int p = 0;
    int p1 = 100;
    int* i_ptr = new int(10);

    //Execute pointer based func
    cout << "\nPointerFunc:" << endl;
    int new_p = *PointerFunc(&p);
    int *i_ptr1 = PointerFunc(i_ptr);
    cout << "PointerFunc results: " << new_p << ", " << *i_ptr1 << endl;

    p = 0;
    *i_ptr1 = 10;

    //Execute reference based func
    cout << "\nReferenceFunc(int& p):" << endl;
    new_p = ReferenceFunc(p);       //l-values executes int &ReferenceFunc(int& p);
    i_ptr1 = &ReferenceFunc(*i_ptr);
    cout << "ReferenceFunc(int& p) results: " << new_p << ", " << *i_ptr1 << endl;

    //Execute const reference based func
    cout << "\nReferenceFunc(const int& p):" << endl;
    //r-values can't be changed, and assumed as const type&
    const int c_i = 25;
    ReferenceFunc(c_i);             //const int also uses &ReferenceFunc(const int& p);
    ReferenceFunc(p+p);             //temp variables are r-values
    new_p = ReferenceFunc(5);       //r-values executes int &ReferenceFunc(const int& p);
    cout << "ReferenceFunc(const int &p) results: " << new_p << ", " << *i_ptr1 << endl;

    //Funcs returning references can be used as l-value
    cout << "\nReferenceFunc as l-value:" << endl;
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
    int& r_1 = r; //r_1 refers to p

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

int &ReferenceFunc(int& p)
{
    cout << "ReferenceFunc(int& p); p = "<< p << endl;
    p += 10;
    return p;
}

int &ReferenceFunc(const int &p)
{
    cout << "ConstReferenceFunc(const int &p); p = " << p << endl;
    int i = 5;
    return i;
}