//Write a program that reads a simple mathematical expression
//(operators allowed: +,-,/, *), and prints its value.

#include <iostream>
using namespace std;

int main() {

    double arg1, arg2, res;
    char op;

    cout<<"Please enter an expression of the form arg1 op arg2: "<<endl;
    cin>>arg1>>op>>arg2;

    switch (op){
        case '+':
            res = arg1 + arg2;
            cout<<res<<endl;
            break;
        case '-':
            res = arg1 - arg2;
            cout<<res<<endl;
            break;
        case '*':
            res = arg1*arg2;
            cout<<res<<endl;
            break;
        case '/':
            if(arg2 != 0){
                res = arg1 / arg2;
                cout<<res<<endl;
            }
            else{
                cout<<"Illegal expression";
            }
            break;
        default:
            cout<<"Illegal expression"<<endl;
            break;

    }

    return 0;
}