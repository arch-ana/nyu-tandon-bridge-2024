#include <iostream>
using namespace std;

int main()
{
    int num, sumDigits, countDigits, currDigit;

    cout<<"Enter a positive integer: "<<endl;
    cin>>num;

    sumDigits = 0;
    countDigits = 0;

    while(num > 0)
    {
        currDigit = num%10;
        countDigits++;
        sumDigits += currDigit;
        num /= 10;
    }
    
    cout<<num<<" has "<<countDigits<< " digits, and their sum is "<<sumDigits<<endl;
    
    return 0;
}