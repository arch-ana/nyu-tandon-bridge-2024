#include <iostream>
#include <string>
using namespace std;

int startAndEndOfWords(string str, int arr[]);
string convertToX(string str, int startAndEndToCheck[], int lenOfIndiceArr);
int main(){

    string str;

    cout<<"Please enter a line of text: ";
    getline(cin, str);

    int arrStartAndEndOfWords[str.length()];
    
    int lenIndices = startAndEndOfWords(str, arrStartAndEndOfWords);

    for (int i = 0; i < lenIndices; i++){
        cout<<arrStartAndEndOfWords[i]<<" ";
    }
    cout<<endl;
    cout<<"length: "<<lenIndices;
    cout<<endl;

    string sentence = convertToX(str, arrStartAndEndOfWords, lenIndices);
    
    cout<<sentence<<endl;

    return 0;
}

//find indices beginning and ending of each word
int startAndEndOfWords(string str, int arr[]){

    arr[0] = 0;
    int k = 1;
    
    for (int i = 0; i<str.length(); i++){
        if (str[i] == ' '){
            arr[k] = i-1;
            k++;
            arr[k] = i+1;
            k++;
        }
    }
    
    arr[k] = str.length() - 1;
    return k+1;
}

//for every pair of entries in the array, check if the word within the
//pair is entirely numeric
string convertToX(string str, int startAndEndToCheck[], int lenOfIndiceArr){
    
    for (int i = 0; i<lenOfIndiceArr; i++){
        if (i%2 == 0){
            
            bool isInteger = true;
            
            for (int j = startAndEndToCheck[i]; j <= startAndEndToCheck[i+1]; j++){
                if (int(str[j]) > 57 || int(str[j]) < 48){
                    isInteger = false;
                }
            }
            if (isInteger){
                for (int j = startAndEndToCheck[i]; j <= startAndEndToCheck[i+1]; j++){
                    str[j] = 'x';
                }
            }
        }
    }
    
    return str;
}

