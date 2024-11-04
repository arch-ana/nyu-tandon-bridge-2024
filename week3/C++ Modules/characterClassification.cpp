#include <iostream>
using namespace std;

int main() {

    char inputChar;

    cout<<"Please enter a character: ";
    cin>>inputChar;

    if (inputChar >= 'a'&& inputChar <= 'z')
        cout<<inputChar<<" is lower case";
    else if (inputChar >= 'A' && inputChar <= 'Z')
        cout<<inputChar<<" is upper case";
    else if (inputChar >= '0' && inputChar <= '9')
        cout<<inputChar<<" is a digit";
    else
        cout<<inputChar<<" is not an alpha-numeric character"<<endl;

    return 0;
}