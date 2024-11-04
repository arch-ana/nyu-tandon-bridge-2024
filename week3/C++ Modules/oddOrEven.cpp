#include <iostream>
using namespace std;

int main() {

    int inputInteger;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>inputInteger;

    if (inputInteger % 2 == 0) {
        cout<<inputInteger<<" is even"<<endl;
    }
    else {
        cout<<inputInteger<<" is odd"<<endl;
    }
    return 0;

    }