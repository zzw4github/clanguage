#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char *a[] = {"Wel", "To", "China"};
    char **p = a;
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < strlen(a[i]) + 1; j++)
        {
            cout << a[i][j] << "\t" << (void *)&a[i][j] << endl;
        }
        cout << endl;
    }
    
    for (int i = 0; i < 3; i++)
    {
        cout << "a[" << i << "] = " << (void *) a[i] << endl
             << "&a[" << i << "] = " << &a[i] << endl;
    } 


    cout << "p  = " << p << endl
         << "&p = " << &p << endl;
    return 0;
}