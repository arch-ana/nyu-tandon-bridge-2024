#include <iostream>
using namespace std;

int main()
{
    int inputPennies, inputNickels, inputDimes, inputQuarters, cents, dollars, remainingCents;

    cout<<"Please enter the number of pennies, nickels, dimes and quarters seperated by spaces: "<<endl;
    cin>>inputPennies>>inputNickels>>inputDimes>>inputQuarters;    
    
    cents = (inputPennies*1) + (inputNickels*5) + (inputDimes*10) + (inputQuarters*25);
    dollars = cents / 100;
    remainingCents = cents % 100;

    cout<<inputPennies<< ", "<<inputNickels<<" ,"<<inputDimes<<" and "<<inputQuarters<<" is "<<dollars<< " dollars and "<<remainingCents<<" cents." <<endl;

    return 0;
}