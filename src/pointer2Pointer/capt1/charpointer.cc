#include <iostream>
using namespace std;

int main()
{
    char a[] = "hello";
    char *p = a;

    cout << "p = " << p << endl
         <<"p = " << (void *) p << endl
         << "*p = " << *p << endl;
        
        
    for(int i = 0 ; i < 5; i++)
    {
        cout << "&a[" << i << "] = "<< (void *)&a[i] << endl;
    }
    return 0;
}