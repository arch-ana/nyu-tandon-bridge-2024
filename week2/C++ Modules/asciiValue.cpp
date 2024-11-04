#include <iostream>
using namespace std;

int main()
{
    char inputChar; //will hold the character entered by user
    int asciiValue; //will hold the ASCII value of the character

    cout<<"Please enter a character: "<<endl;
    cin>>inputChar;    
    
    asciiValue = (int)inputChar;

    cout<<"The ASCII value of "<<inputChar<<" is "<<asciiValue<<endl;

    return 0;
}