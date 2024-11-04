#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    char ch;

    str1 = "abcdef";
    cout<<str1[0]<<" "<<str1[1]<<" "<<str1[2]<<endl;
    ch = str1[3];

    cout<<str1.length();

    return 0;
}