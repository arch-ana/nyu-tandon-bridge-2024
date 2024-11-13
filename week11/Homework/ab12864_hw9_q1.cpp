#include <iostream>
#include <string>
using namespace std;

int numberOfWords(string str);
void numberOfLetters(string str, int arrOccurences[]);
int main(){

    string str;
    int arrOccurrences[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, str);

    int words = numberOfWords(str);

    cout<<words<<"\twords"<<endl;

    numberOfLetters(str, arrOccurrences);

    for (int i = 0; i<26; i++){
        if (arrOccurrences[i] != 0){
            cout<<arrOccurrences[i]<<"\t"<<char(i+97)<<endl;
        }
    }

    return 0;
}

int numberOfWords(string str){

    int start = -1, end = -1, counter = 0, letters[26];

    for (int i = 0; i < str.length(); i++){
        if ((int(str[i]) >= 97 && int(str[i]) <= 122) || (int(str[i]) >= 65 && int(str[i]) <= 90)){
            if (str[i-1] == ' ' || str[i-1] == ',' || str[i-1] == '.' || i == 0){
                start = i;
            }
            if (str[i+1] == ' ' || str[i+1] == ',' || str[i+1] == '.' || i == str.length()-1){
                end = i;
            }
        }
        if (start != -1 && end != -1){
            counter += 1;
            start = -1;
            end = -1;
        }
    }
    return counter;
}

void numberOfLetters(string str, int arrOccurences[]){
    for (int i = 0 ; i < str.length(); i++){
        if (int(tolower(str[i])) >= 97 || int(tolower(str[i])) <= 122){
            int k = int(tolower(str[i])) - 97;
            arrOccurences[k] += 1;
        }
    }
}