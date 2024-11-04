#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "abcdefghifg";
    //Finding characters within a string
    cout<<str.find("de")<<endl;
    

    //When a find result fails
    if (str.find("xyz") == string::npos)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Found"<<endl;
    }

    //Repeated occurence within a string
    cout<<str.find("fg");
}