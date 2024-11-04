#include <iostream>
using namespace std;

int main()
{
	int n, maximum, minimum, groupA, groupB, groupC, groupD, totalPeople, sumOfAge;
	bool seenEndOfInput;
	double average;
	
	cout<<"Please enter ages as a sequence of numbers, each one in a separate line. ";
	cout<<"Type -1 to indicate the end of the sequence: "<<endl;

	seenEndOfInput = false;
	totalPeople = 0;
	sumOfAge = 0;
	maximum = 1;
	minimum = 100;
	groupA = 0;
	groupB = 0;
	groupC = 0;
	groupD = 0;
	average = 0;

	while (seenEndOfInput == false)
	{
		cin>>n;
		
		if (n != -1)
		{
			totalPeople += 1;
			sumOfAge += n;
			
			if (n > maximum)
			{
				maximum = n;
			}
			if (n < minimum) 
			{
				minimum = n;
			}

			if (n < 21)
			{
				groupA += 1;
			}
			else if (n >= 21 && n <= 35)
			{
				groupB += 1;
			}
			else if (n >= 36 && n <= 50)
			{
				groupC += 1;
			}
			else
			{
				groupD += 1;
			}			
		}
		else
		{
			seenEndOfInput = true;
		} 
	}
    
    average = (double)sumOfAge/(double)totalPeople;
    
    int largestGroupSize = -1;
	char largestGroupName = ' ';

	if (groupA > largestGroupSize)
	{
		largestGroupName = 'A';
		largestGroupSize = groupA;
	}
	if (groupB > largestGroupSize)
	{
		largestGroupName = 'B';
		largestGroupSize = groupB;
	}
	if (groupC > largestGroupSize)
	{
		largestGroupName = 'C';
		largestGroupSize = groupC;
	}
	if (groupD > largestGroupSize)
	{
		largestGroupName = 'D';
		largestGroupSize = groupD;
	}	
	
	if (totalPeople == 0)
    {
        maximum = 0;
        minimum = 0;
        average = 0;
    }
	

	cout<<"Number of people in the age group A: "<<groupA<<endl;
	cout<<"Number of people in the age group B: "<<groupB<<endl;
	cout<<"Number of people in the age group C: "<<groupC<<endl;
	cout<<"Number of people in the age group D: "<<groupD<<endl;
	cout<<"Total number of people in the sequence: "<<totalPeople<<endl;
	cout<<"Maximum age among the sequence: "<<maximum<<endl;
	cout<<"Minimum age among the sequence: "<<minimum<<endl;
	cout<<"Average age: "<<average<<endl;
	cout<<"Group with most people: "<<largestGroupName<<endl;
	
	
	return 0;

}