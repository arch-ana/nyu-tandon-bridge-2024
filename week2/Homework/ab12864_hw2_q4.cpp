#include <iostream>
using namespace std;

int main()
{
    int num1, num2, sum, difference, product, div, mod;
    float division;

    cout<<"Please enter two positive integer seperated by a space:"<<endl;
    cin>>num1>>num2;
    
    sum = num1 + num2;
    difference = num1-num2;
    product = num1*num2;
    division = float(num1)/float(num2);
    div = num1 / num2;
    mod = num1 % num2;

    cout<<num1<<" + "<<num2<<" = "<<sum<<endl;
    cout<<num1<<" - "<<num2<<" = "<<difference<<endl;
    cout<<num1<<" * "<<num2<<" = "<<product<<endl;
    cout<<num1<<" / "<<num2<<" = "<<division<<endl;
    cout<<num1<<" div "<<num2<<" = "<<div<<endl;
    cout<<num1<<" mod "<<num2<<" = "<<mod<<endl;

    return 0;
}