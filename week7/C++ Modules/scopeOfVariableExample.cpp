#include <iostream>
using namespace std;

void func(int n);

int main()
{
    int n = 3;

    cout<<"Before function: "<<n<<endl;
    func(n);
    cout<<"After function: "<<n<<endl;

    return 0;
}

void func(int n)
{
    n = 4;

    cout<<"Inside func: "<<n<<endl;
}