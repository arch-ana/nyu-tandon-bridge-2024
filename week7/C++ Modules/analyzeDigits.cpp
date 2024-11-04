//Print the number and sum of digits in a positive integer
//Two outputs and one input, we will use call by reference


#include <iostream>
using namespace std;

int analyzeDigits(int num, int& outSum);

int main()
{
    int num, numberOfDigits, sumOfDigits;
    
    cout<<"Please enter a positive integer: ";
    cin>>num;

    numberOfDigits = analyzeDigits(num, sumOfDigits);

    cout<<num<<" has "<<numberOfDigits<<" digits and their sum is "<<sumOfDigits;

    return 0;
}

int analyzeDigits(int num, int& outSum)
{
    int count, sum;
    int currDig;

    count = 0;
    sum = 0;

    while (num > 0)
    {
        currDig = num % 10;
        count += 1;
        sum += currDig;
        num /= 10;
    }

    outSum = sum;
    return count;
}