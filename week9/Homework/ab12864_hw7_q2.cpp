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
    cout<<"Following are perfect numbers between 2 and "<<userInput<<": "<<endl;
    for (int i = 2; i <= userInput; i++)
    {
        if (isPerfect(i))
        {
            cout<<i<<endl;
        }
    }
    cout<<endl;

    //prints all amicable numbers
    //amicable numbers add up to each others perfect divisors
    cout<<"Following are amicable numbers between 2 and "<<userInput<<endl;
    for (int i = 2; i <= userInput; i++)
    {
        int iNumberOfDivisors = 0, iSumOfDivisors = 0;

        if (isPerfect(i) == false)
        {
            analyzeDividors(i, iNumberOfDivisors, iSumOfDivisors);
        }

        int j = iSumOfDivisors;
        int jNumberOfDivisors = 0, jSumOfDivisors = 0;
        analyzeDividors(j, jNumberOfDivisors, jSumOfDivisors);

        if (i<j && iSumOfDivisors == j && jSumOfDivisors == i)
        { 
            cout<<i<<" and "<<j<<endl;
        }
    }
}

//function that analyzes a given number, finds the sum of its proper roots and the number of its proper roots
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

//function that checks if a number if a perfect number
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
