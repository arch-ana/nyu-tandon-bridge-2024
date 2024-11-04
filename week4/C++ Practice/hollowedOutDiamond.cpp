#include <iostream>
using namespace std;

int main()
{
    int userInput;

    cout<<"Please enter a positive integer: ";
    cin>>userInput;

    char LETTER = 'a';
    char SPACE = ' ';
    int outSpace = userInput - 1;
    int inSpace = 0;

    for(int i = 1; i < 2*userInput; i++)
    {
        //outspaces
        for(int j = 1; j <= outSpace; j++)
        {
            cout<<SPACE;
        }

        //first letter
        cout<<LETTER;

        //inspaces
        for(int j = 1; j <= inSpace; j++)
        {
            cout<<SPACE;
        }

        //second letter
        if (i != 1 && i != 2*userInput-1)
            cout<<LETTER;

        if (i < userInput)
        {
            inSpace += 2;
            outSpace -=1;
            LETTER += 1;
        }
        else
        {
            inSpace -= 2;
            outSpace += 1;
            LETTER -= 1;
        }
        
        cout<<endl;

    }

    return 0;
}