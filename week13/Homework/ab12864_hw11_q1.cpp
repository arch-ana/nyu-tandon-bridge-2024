#include <iostream>
using namespace std;

const char ASTERISK = '*', HYPHEN = '-';

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);
int main(){

    printTriangle(4);
    cout<<endl;
    cout<<endl;
    printOppositeTriangles(4);
    //printRuler(4);

    return 0;
}
//function 1
void printTriangle(int n){
    if (n==1){
        cout<<ASTERISK;
    }
    else{
        printTriangle(n-1);
        cout<<endl;
        for (int i = 1; i<= n; i++){
            cout<<ASTERISK;
        }
    }
}

//function 2
void printOppositeTriangles(int n){
    if (n==1){
        cout<<ASTERISK<<endl;
    }
    else{
        for (int i = 1; i <= n; i++){
            cout<<ASTERISK;
        }
        cout<<endl;
        printOppositeTriangles(n-1);
        for (int i = 1; i <= n; i++){
            cout<<ASTERISK;
        }
        cout<<endl;
    }
}

//function 3
void printRuler(int n){
    if (n==1){
        cout<<HYPHEN;
    }
    else{
        printRuler(n-1);
        cout<<endl;
        for (int i = 1; i <= n; i++){
            cout<<HYPHEN;
        }
        cout<<endl;
        printRuler(n-1);
    }
}
