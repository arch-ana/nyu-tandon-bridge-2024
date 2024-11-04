//Write a program that asks a user to input a positive integer n, and prints 
//a textual image of an hourglass made of 2n lines with asterisks. 

#include <iostream>
using namespace std;

int main() 
{
    int n, emptySpaceInLine, asterisksInLine, lineNumber;

    cout<<"Enter a positive integer n: ";
    cin>>n;

    //First n lines will go in decreasing order of asterisks

    emptySpaceInLine = 0;
    asterisksInLine = 2*n-1;

    for (lineNumber = 1; lineNumber <= n; lineNumber++)
    {
        
        for (int i = 0; i < emptySpaceInLine; i++)
            cout<<" ";
        emptySpaceInLine += 1;

        
        for (int asterisks = 0; asterisks < asterisksInLine; asterisks++)
            cout<<"*";
        asterisksInLine -= 2;

        cout<<"\n";
    }

    //Next n lines will go in increasing order of asterisks

    emptySpaceInLine = n-1;
    asterisksInLine = 1;

    for (lineNumber = 1; lineNumber <= n; lineNumber++)
    {
        
        for (int j = 0; j < emptySpaceInLine; j++)
            cout<<" ";
        emptySpaceInLine -= 1;

        
        for (int asterisks = 0; asterisks < asterisksInLine; asterisks++)
            cout<<"*";
        asterisksInLine += 2;

        cout<<"\n";
    }
    
    return 0;
}