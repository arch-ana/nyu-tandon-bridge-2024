#include <iostream>
#include <cmath>

using namespace std;

void printDivisors (int num);
int main()
{
    int num;
    
    cout<<"Please enter a positive integer: ";
    cin>>num;

    printDivisors(num);
}

void printDivisors(int num)
{
    for (int i = 1; i < sqrt(num); i++)
    {
        if (num%i == 0)
        {
            cout<<i;
            cout<<" ";
        }
    }
    for (int i = sqrt(num); i >= 1; i--)
    {
        if (num%i == 0)
        {
            cout<<num/i;
            cout<<" ";
        }
    }
}