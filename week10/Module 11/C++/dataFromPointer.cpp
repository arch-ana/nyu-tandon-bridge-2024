#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 100;
    int *ptr;
    ptr = &x;
    cout<<*ptr<<endl;
    
    *ptr = 20;
    cout<<*ptr<<endl;

    x = 33;
    cout<<*ptr<<endl;

    return 0;
}