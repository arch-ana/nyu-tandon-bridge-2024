#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word1, word2, word3;

    cout<<"Please enter three words seperated by space: ";
    cin>>word1>>word2>>word3;

    if (word1 <= word2 && word1 <= word3)
    {
        cout<<word1<<endl;
    }
    if (word2 <= word1 && word2 <= word3)
    {
        cout<<word2<<endl;
    }
    else
    {
        cout<<word3;
    }
    
    return 0;
}