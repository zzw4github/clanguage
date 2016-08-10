#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int * p = &a;
    cout << "a  = " <<  a << endl
         << "&a = " << &a << endl 
         << "*p = " << *p << endl 
         << "p  = " << p << endl 
         << "&p = " << &p << endl;

    return 0;
}