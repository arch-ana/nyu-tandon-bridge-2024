#include <iostream>

using namespace std;

int main() {

    int userInput, counter;

    cout<<"Please enter a positive integer: ";
    cin>>userInput;

    counter = 1;

    while (counter <= userInput)
    {
        cout<<counter<<endl;
        counter++;
    }

    return 0;
}