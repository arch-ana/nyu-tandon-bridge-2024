#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    str1 = "abc";
    str2 = "de";

    if (str1<str2)
    {
        cout<<str1<<" is smaller than "<<str2<<endl;
    }
    else
    {
        cout<<str1<<" is not smaller than "<<str2<<endl;
    }
    return 0;
}