#include <iostream>
#include <string>
using namespace std;

int IndexOfSpaces(string str, int arr[]);
int main(){

    string str;

    cout<<"Please enter a line of text: ";
    getline(cin, str);

    int indicesOfSpaces[str.length()], lastIndiceInSpacesArray;
    
    lastIndiceInSpacesArray = IndexOfSpaces(str, indicesOfSpaces);
    cout<<"Value of k = "<<lastIndiceInSpacesArray<<endl;

    for (int i = 0; i <= lastIndiceInSpacesArray; i++){
        cout<<indicesOfSpaces[i]<<" ";
    }

    cout<<"Length of string: "<<str.length();

    return 0;
}

//find indices of all spaces
int IndexOfSpaces(string str, int arr[]){

    int k = 0;
    
    for (int i = 0; i<str.length(); i++){
        if (str[i] == ' '){
            arr[k] = i;
            k++;
        }
    }

    return k-1;
}


//for every two consecutive index values stored in array, check if the corresponding value
//in the string has all integer values. if yes, store these indices in an array. 



