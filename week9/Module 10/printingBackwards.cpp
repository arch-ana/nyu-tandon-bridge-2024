#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;

    cout<<"Please enter your name: "<<endl;
    getline(cin, name);

    for (int i = (name.length()-1); i >= 0; i--)
    {
        cout<<name[i];
    }
    
    return 0;
}