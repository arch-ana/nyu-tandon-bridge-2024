//write a recursive implementation for the function:
//void printAsc(int start, int end);
//The function should print the numbers from start to end in ascending 
//order (Assume start < end)

#include <iostream>
using namespace std;

void printAsc(int start, int end);
int main(){

    int start, end;

    cout<<"Enter start: ";
    cin>>start;
    cout<<"Enter end: ";
    cin>>end;

    printAsc(start, end);

    return 0;
}

void printAsc(int start, int end){
    //The base case
    if (start == end){
        cout<<start<<endl;
    }
    //Inductive step
    else{
        printAsc(start, end-1);
        cout<<end<<endl;
    }
}
