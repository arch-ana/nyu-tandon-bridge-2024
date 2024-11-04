#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    char ch;

    str1 = "abcdefg";
    str2 = "lmnopq";

    cout<<str1[0]<<" "<<str1[1]<<" "<<str1[2]<<endl;
    cout<<str2[0]<<" "<<str2[1]<<" "<<str2[2]<<endl;

    ch = str2[3];

    cout<<"Character: "<<ch;

    return 0;
}