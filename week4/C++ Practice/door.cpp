#include <iostream>
using namespace std;

int main()
{
	int userInput;

	cout<<"Please enter a positive integer: "<<endl;
	cin>>userInput;

	const char ASTERISK = '*';
	const char SPACE = ' ';

	for (int i = 1; i <= (2*userInput - 1); i++)
	{
		for (int j = 1; j <= 2*userInput; j++)
		{
			if (i <= userInput && i <= j)
			{
				cout<<ASTERISK;
			}
			else if (i <= userInput && (i + j) >= 2*userInput + 1)
			{
				cout<<ASTERISK;
			}
			else if (i > userInput && i >= j+2)
			{
				cout<<ASTERISK;
			}
			else if (i > userInput &&  (i + j) >= 2*userInput + 3)
			{
				cout<<ASTERISK;
			}
			else
			{
				cout<<SPACE;
			}
		  
		}

		cout<<endl;
	} 
	return 0;
}