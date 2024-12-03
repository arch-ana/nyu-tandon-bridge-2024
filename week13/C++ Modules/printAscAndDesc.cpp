#include <iostream>
using namespace std;

void printAscAndDesc(int start, int end);
int main(){

    printAscAndDesc(5,10);

    return 0;
}

void printAscAndDesc(int start, int end){
    if (start == end){
        cout<<start<<endl;
    }
    else{
        cout<<start<<endl;
        printAscAndDesc(start+1, end);
        cout<<start<<endl;
    }
}