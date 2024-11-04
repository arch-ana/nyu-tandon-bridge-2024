#include <iostream>
using namespace std;

int main() 
{
    int userInput, counter, n, nextEvenNumber;

    cout<<"Please enter a positive integer: ";
    cin>>userInput;

    cout<<"Section A: The first "<<userInput<<" even integers using a while loop are:"<<endl;

    counter = userInput;
    n = 1;

    while (counter != 0)
    {
        nextEvenNumber = 2*n;
        cout<<nextEvenNumber<<endl;
        counter -= 1;
        n += 1;
    }
    
    cout<<"Section B: The first "<<userInput<<" even integers using a for loop are:"<<endl;

    for (n = 1; n <= userInput; n++)
    {
        cout<<2*n<<endl;
    }
    
    
    return 0;
}