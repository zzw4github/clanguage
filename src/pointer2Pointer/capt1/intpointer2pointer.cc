#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    int **point = &p;

    cout <<"a      = " << a << endl
        << "p       = " << p << endl
        << "*p      = " << *p << endl
        << "&p      = " << &p << endl
        << "point   = " << point << endl
        << "*point  = " << *point << endl
        << "&point  = " << &point << endl
        << "**point = " << **point << endl;

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "&a[" << i << "] = " << &a[i] << endl;
    }
    cout << endl;
     for (int i = 0; i < 5; i++)
    {
        cout << "*&a[" << i << "] = " << *&a[i] << endl;
    }
    return 0;
}