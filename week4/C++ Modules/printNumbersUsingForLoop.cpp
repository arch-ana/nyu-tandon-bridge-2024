#include <iostream>

using namespace std;

int main()
{

    int userInput, counter;

    cout<<"Enter a positive integer: ";
    cin>>userInput;

    counter = 1;

    for (counter = 1; counter <= userInput; counter++)
    {
        cout<<counter<<endl;
    }
    
    return 0;
}