//Fibonacci sequence

#include <iostream>
using namespace std;

int fib(int n);
int main()
{
    int n, nthElement;

    cout<<"Please enter a positive integer: ";
    cin>>n;

    if (n > 2)
    {   
        nthElement = fib(n);
    }
    else
    {
        nthElement = 1;
    }

    cout<<nthElement;    
    
    return 0;
}

int fib(int n)
{
    int fn_2 = 1, fn_1 = 1, fn;

    for (int i = 3; i <= n; i++)
    {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;    
    }
    return fn;
}