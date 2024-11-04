#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);

bool isPerfect(int num);

int main()
{
    int userInput;

    cout<<"Please enter a positive integer >= 2: ";
    cin>>userInput;

    //prints all numbers that are perfect numbers
    cout<<"The following are perfect numbers between 2 and "<<userInput<<": "<<endl;
    for (int i = 2; i <= userInput; i++)
    {
        if (isPerfect(i))
        {
            cout<<i<<endl;
        }
    }

    //prints all amicable numbers
    //amicable numbers add up to each others perfect divisors
    cout<<"The following are amicable pairs of numbers between 2 and "<<userInput<<": "<<endl;
    for (int i = 1; i <= userInput; i++)
    {
        int amicableNumber = 0, numberOfDivisors = 0, sumOfDivisors = 0;

        if (isPerfect(i) == false)
        {
            analyzeDividors(i, numberOfDivisors, sumOfDivisors);
        }
    }
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num%i == 0)
        {
            if (num/i != i)
            {
                outCountDivs += 2;
                outSumDivs += (i + (num/i));
            }
            else
            {
                outCountDivs += 1;
                outSumDivs += i;
            }
        }
    }
    outCountDivs += 1;
    outSumDivs += 1;
}

bool isPerfect(int num)
{
    int outCountDivs = 0, outSumDivs = 0;
    analyzeDividors(num, outCountDivs, outSumDivs);
    if (num == outSumDivs)
    {
        return true;
    }
    else
    {
        return false;
    } 
}
