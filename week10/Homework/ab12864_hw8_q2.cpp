#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(string str);
int main(){
    string userInput;

    cout<<"Please enter a word: ";
    cin>>userInput;

    if (isPalindrome(userInput)){
        cout<<userInput<<" is a palindrome"<<endl;
    }
    else{
        cout<<userInput<<" is not a palindrome"<<endl;
    }

    return 0;
}

bool isPalindrome(string str){

    int palindrome = 1;

    for (int i = 0; i < str.length(); i++){
        if (str[i] != str[(str.length() - 1) - i]){
            palindrome = 0;
            break;
        }
    }
    return palindrome == 1;
}