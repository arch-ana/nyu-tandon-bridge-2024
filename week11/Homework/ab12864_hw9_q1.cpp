#include <iostream>
#include <string>
using namespace std;

int main(){

    string str;

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, str);

    return 0;
}

int numberOfWords(string str){

    int counter = 0;

    for (int i = 0; i < str.length(); i++){
        if (str[i] == ' ' || str[i] == '.' || str[i] == ','){
            counter += 1;
        }
    }
}