#include <iostream>
using namespace std;

int main()
{
    int userInput;
    const char SPACE = ' ';
    const char POUND = '#';
    const char DOLLAR = '$';

    cout<<"Please enter a positive integer: ";
    cin>>userInput;

    for (int i = 1; i <= userInput; i++)
    {
        for (int j = 1; j <= userInput; j++)
            if (i == 1 || j == 1 || i == userInput || j == userInput)
            {
                cout<<POUND;
            }
            else if (i == j || i + j == userInput + 1)
            {
                cout<<DOLLAR;
            }
            else
            {
                cout<<SPACE;
            }
        cout<<endl;
    }
    return 0;
}