#include <iostream>
using namespace std;

int main()
{
	int n;
	int beginAsterisks, spaces, endAsterisks;
	const char ASTERISK = '*';
	const char SPACE = ' ';

	cout<<"Please enter a positive integer n: ";
	cin>>n;

	beginAsterisks = 1;
	spaces = 2*n - 2;
	endAsterisks = 1;

	for (int i = 1; i <= 2*n - 1; i++)
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
		if (i <= n - 1)
		{
			beginAsterisks += 1;
			spaces -= 2;
			endAsterisks +=1;
		}
		else
		{
			beginAsterisks -= 1;
			spaces += 2;
			endAsterisks -= 1;
		}

		cout<<"\n";
	}
	return 0;
}