#include <iostream>
using namespace std;

int main()
{
	int n;

	cout<<"Please enter a positive integer: "<<endl;
	cin>>n;

	int numberOfSpaces = n - 1;
	int numberOfAsterisks = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= numberOfAsterisks; j++)
		{
			cout<<"*";
		}
		for (int j = 1; j <= numberOfSpaces; j++)
		{
			cout<<" ";
		}
		numberOfSpaces -= 1;
		numberOfAsterisks += 1;
		cout<<"\n";			
	}

	return 0;
}