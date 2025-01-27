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
    cout<<"First: "<<str.find("fg")<<endl;
    //Repeated occurence but we specify from which index to search
    cout<<"After index 7: "<<str.find("fg", 7)<<endl;
}