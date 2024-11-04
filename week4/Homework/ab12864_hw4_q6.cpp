//Write a program that asks the user to input a positive integer n. 
//Print all numbers from 1-n that have more even digits than odd digits. 

#include <iostream>
using namespace std;

int main() 
{
    int userInput, i, evenDigit, oddDigit, numberBeingChecked, multiplier, lastDigit;

    cout<<"Enter a positive integer: ";
    cin>>userInput;

    cout<<"Numbers from 1 to "<<userInput<<" that have more even digits than odd are: "<<endl;
    
    for (i = 1; i <= userInput; i++)
    {
        evenDigit = 0;
        oddDigit = 0;
        multiplier = 10;
        
        numberBeingChecked = i;

        while (numberBeingChecked>0)
        {   
            lastDigit = numberBeingChecked%multiplier;
            if (lastDigit%2 == 0)
            {    
                evenDigit += 1;
            }
            else
            {    
                oddDigit += 1;
            }
            numberBeingChecked /= multiplier;
        }

        if (evenDigit > oddDigit)
        {
            cout<<i<<endl;
        }
    }
    
    return 0;
}
