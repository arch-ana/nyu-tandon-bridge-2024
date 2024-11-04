#include <iostream>
using namespace std;

int main()
{
    int inputPennies, inputNickels, inputDimes, inputQuarters, cents, dollars, remainingCents;

    cout<<"Please enter number of coins:\n";
    cout<<"# of quarters: "<<endl;
    cin>>inputQuarters;
    cout<<"# of dimes: "<<endl;
    cin>>inputDimes;
    cout<<"# of nickels: "<<endl;
    cin>>inputNickels;
    cout<<"# of pennies: "<<endl;
    cin>>inputPennies;    
    
    cents = (inputQuarters*25) + (inputDimes*10) + (inputNickels*5) + (inputPennies*1)   ;
    dollars = cents / 100;
    remainingCents = cents % 100;

    cout<<"The total is "<<dollars<< " dollars and "<<remainingCents<<" cents." <<endl;

    return 0;
}