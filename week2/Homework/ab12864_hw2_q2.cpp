#include <iostream>
using namespace std;

int main()
{
    int inputDollars, inputCents, totalAmount, quarters, dimes, nickels, pennies;

    cout<<"Please enter your amount in the format of dollars and cents seperated by a space: "<<endl;
    cin>>inputDollars>>inputCents;    
    
    totalAmount = (inputDollars*100) + inputCents;
    
    quarters = totalAmount/25;
    
    dimes = (totalAmount % 25) / 10;
    
    nickels = ((totalAmount % 25) % 10) / 5;
    
    pennies = (((totalAmount % 25) % 10) % 5);
    
    cout<<inputDollars<<" dollars and "<<inputCents<<" cents are: \n";
    cout<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels and "<<pennies<<" pennies."<<endl;

    return 0;
}