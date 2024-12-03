#include <iostream>
using namespace std;

const char ASTERISK = '*', HYPHEN = '-';

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);
int main(){
    
    int n;
    
    cout<<"Enter integer n: ";
    cin>>n;

    cout<<"Triangle"<<endl;
    printTriangle(n);
    cout<<endl;
    cout<<"Opposite triangles"<<endl;
    printOppositeTriangles(n);
    cout<<endl;
    cout<<"Ruler"<<endl;
    printRuler(n);
    cout<<endl;

    return 0;
}
//function 1
void printTriangle(int n){
    if (n==1){
        cout<<ASTERISK<<endl;
    }
    else{
        printTriangle(n-1);
        for (int i = 1; i<= n; i++){
            cout<<ASTERISK;
        }
        cout<<endl;
    }
}

//function 2
void printOppositeTriangles(int n){
    if (n==1){
        cout<<ASTERISK<<endl<<ASTERISK<<endl;
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
