#include <iostream>
#include <cmath>

using namespace std;

int main() 
{

    int userInput, base, counter, curr, lengthOfSequence;
    double geometricMean, exponent;
    bool seenEndOfInput;

    cout<<"Section A: Using length of the sequence as entered by the user"<<endl;
    
    cout<<"Please enter the length of the sequence: ";
    cin>>userInput;
    exponent = double(1.0/userInput);

    cout<<"Please enter your sequence of positive integers, each number in a separate line: "<<endl;

    base = 1;
    for (counter = 1; counter <= userInput; counter++)
    {
        cin>>curr;
        base *= curr;
    }
    
    geometricMean = pow(base, exponent);

    cout.setf(ios::fixed); 
    cout.setf(ios::showpoint); 
    cout.precision(4);
    cout<<"The geometric mean is: "<<geometricMean<<endl;

    cout<<"\n";
    cout<<"Section B: Calculating length of sequence based on the occurence of -1"<<endl;

    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: "<<endl;

    curr = 0;
    lengthOfSequence = 0;
    seenEndOfInput = false;
    base = 1;

    while (seenEndOfInput == false)
    {
        cin>>curr;
        if (curr == -1)
        {   
            seenEndOfInput = true;
        }
        else 
        {
            base *= curr;
            lengthOfSequence += 1;
        }
    }

    exponent = double(1.0/lengthOfSequence);

    geometricMean = pow(base, exponent);

    cout.setf(ios::fixed); 
    cout.setf(ios::showpoint); 
    cout.precision(4);
    cout<<"The geometric mean is: "<<geometricMean<<endl;
    
    return 0;
}