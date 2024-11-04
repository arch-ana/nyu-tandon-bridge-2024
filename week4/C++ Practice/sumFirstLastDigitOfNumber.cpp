#include <iostream>
using namespace std;

int main()
{
	
	int n, firstDigit, lastDigit, sumOfDigits, groupOne, groupTwo, groupThree, groupFour;
	bool seenEndOfInput;

	cout<<"Enter a sequence of positive numbers with atleast 2 digits and at most 8 digits. Type -1 to indicate end of input: ";

	seenEndOfInput = false;
	groupOne = 0;
	groupTwo = 0;
	groupThree = 0;
	groupFour = 0;

	while (seenEndOfInput == false)
	{
		cin>>n;

		if (n != -1)
		{
			firstDigit = n%10;
			n /= 10;			 

			while (n > 0)
			{
				lastDigit = n%10;
				n /= 10;
			}

			sumOfDigits = firstDigit + lastDigit;

			if (sumOfDigits < 5)
			{
				groupOne += 1;
			}
			else if (sumOfDigits >= 5 && sumOfDigits < 10)
			{
				groupTwo += 1;
			}
			else if (sumOfDigits >= 10 && sumOfDigits < 15)
			{
				groupThree += 1;
			}
			else
			{
				groupFour += 1;
			}
				
		}
		else
		{
			seenEndOfInput = true;
		} 
	}	
	

	cout<<"Group 1: "<<groupOne<<endl;
	cout<<"Group 2: "<<groupTwo<<endl;
	cout<<"Group 3: "<<groupThree<<endl;
	cout<<"Group 5: "<<groupFour<<endl;

	return 0;
}