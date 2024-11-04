#include <iostream>
using namespace std;

int main()
{
	int n, numberOfSpaces, numberOfAsterisks;
	const char SPACE = ' ';
	const char ASTERISK = '*';

	cout<<"Please enter a positive integer: ";
	cin>>n;

	numberOfSpaces = 2*n-2;
	numberOfAsterisks = 1;

	for (int i = 1; i <= 4*n-3; i++)
	{
		for (int j = 1; j <= numberOfSpaces; j++)
		{
			cout<<SPACE;
		}
		for (int j = 1; j <= numberOfAsterisks; j++)
		{
			cout<<ASTERISK;
		}
		
		if (i <= 2*n-2)
		{
			numberOfSpaces -= 1;
			numberOfAsterisks += 1;
		}
		else
		{
			numberOfSpaces += 1;
			numberOfAsterisks -= 1;
		}
		cout<<"\n";
			 
	}
	
	return 0;
}
