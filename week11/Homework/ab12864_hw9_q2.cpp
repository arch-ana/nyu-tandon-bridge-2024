//two strings are anagrams if their letters can be rearranged to form each other
//i.e if two words have the same number of occurrences for each letter, then it is an anagram

#include <iostream>
using namespace std;

void numberOfLetters(string str, int arr[]);
int main(){

    string str1;
    string str2;
    int arr1[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int arr2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    cout<<"Please enter your first string: "<<endl;
    getline(cin, str1);
    cout<<"Please enter your second string: "<<endl;
    getline(cin, str2);

    numberOfLetters(str1, arr1);
    numberOfLetters(str2, arr2);

    int anagram = 1;
    for (int i = 0; i<26; i++){
        if (arr1[i] != arr2[i]){
            anagram = 0;
            break;
        }
    }

    if (anagram==1){
        cout<<"The two strings are anagrams"<<endl;
    }
    else{
        cout<<"The two strings are NOT anagrams"<<endl;
    }

    return 0;
}
void numberOfLetters(string str, int arr[]){
    for (int i = 0 ; i < str.length(); i++){
        if (int(str[i]) >= 97 && int(str[i]) <= 122){
            int k = int(str[i]) - 97;
            arr[k] += 1;
        }
        else if (int(str[i]) >= 65 && int(str[i]) <= 90){
            int k = int(str[i]) - 65;
            arr[k] += 1;
        }
    }
}