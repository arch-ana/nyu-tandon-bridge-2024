#include <iostream>
using namespace std;

int main()
{
    int userInput, numberOfM, numberOfD, numberOfC, numberOfL, numberOfX;
    int numberOfV, numberOfI;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>userInput;
    
    
    numberOfM = userInput / 1000;
    userInput -= numberOfM*1000;
    numberOfD = userInput / 500;
    userInput -= numberOfD*500;
    numberOfC = userInput / 100;
    userInput -= numberOfC*100;
    numberOfL = userInput / 50;
    userInput -= numberOfL*50;
    numberOfX = userInput / 10;
    userInput -= numberOfX*10;
    numberOfV = userInput / 5;
    userInput -= numberOfV*5;
    numberOfI = userInput / 1;
    userInput -= numberOfI*1;
    
    cout<<"The Roman numeral equivalent is: ";
    while (numberOfM > 0)
    {
        cout<<"M";
        numberOfM -= 1;
    }
    while (numberOfD > 0)
    {
        cout<<"D";
        numberOfD -= 1;
    }
    while (numberOfC > 0)
    {
        cout<<"C";
        numberOfC -= 1;
    }
    while (numberOfL > 0)
    {
        cout<<"L";
        numberOfL -= 1;
    }
    while (numberOfX > 0)
    {
        cout<<"X";
        numberOfX -= 1;
    }
    while (numberOfV > 0)
    {
        cout<<"V";
        numberOfV -= 1;
    }
    while (numberOfI > 0)
    {
        cout<<"I";
        numberOfI -= 1;
    }
    
    return 0;
}