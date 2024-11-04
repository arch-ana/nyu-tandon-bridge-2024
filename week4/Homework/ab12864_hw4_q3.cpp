#include <iostream>
using namespace std;

int main() 
{
    int userInput, result, multiplier;

    cout<<"Please enter a positive number: ";
    cin>>userInput;
    
    result = 0;
    multiplier = 1;

    while (userInput > 0)
    {
        result = result + ((userInput%2)*multiplier);
        multiplier = multiplier*10;
        userInput = userInput/2;
    }
    
    cout<<"The binary equivalent is "<<result<<endl;
    
    return 0;
}
