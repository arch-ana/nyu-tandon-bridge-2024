#include <iostream>
using namespace std;

int main()
{
	int n;
	const char SPACE = ' ';
	const char ASTERISK = '*';

	cout<<"Please enter a positive integer: ";
	cin>>n;

	int beginAsterisks = 1, spaces = 2*n-2, endAsterisks = 1;

	for (int i = 1; i <= 2*n; i++)
	{
		for (int j = 1; j <= beginAsterisks; j++)
		{
			cout<<ASTERISK;
		}

		for (int j = 1; j <= spaces; j++)
		{
			cout<<SPACE;
		}
		for (int j = 1; j <= endAsterisks; j++)
		{
			cout<<ASTERISK;
		}

		if (i < n)
		{
			beginAsterisks += 1;
			endAsterisks += 1;
			spaces -= 2;
		}
		else
		{
			beginAsterisks -= 1;
			endAsterisks -= 1;
			spaces += 2;
		}
		cout<<endl;
	} 

	return 0;
}