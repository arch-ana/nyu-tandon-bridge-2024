#include<iostream>
using namespace std;

int const PASSWORD = 74619;
int const PASSWORD_LENGTH = 5;
int const LENGTH_OF_ALL_USABLE_DIGITS = 10;

void generateUniqueSequence(int arr[], int sizeArr);
void findIndicesToCheck(int permissibleDigitsArray[], int constantPassword, int indicesToCheck[]);
bool isPasswordMatch(int permissibleDigitsArray[], int userInputArray[], int indicesToCheck[]);

int main(){

    int allUsableDigits[LENGTH_OF_ALL_USABLE_DIGITS] = {0,1,2,3,4,5,6,7,8,9};
    int uniqueSequence[LENGTH_OF_ALL_USABLE_DIGITS];
    int userInput, currDigit;
    int userEnteredSequence[PASSWORD_LENGTH];
    int indicesToCheck[PASSWORD_LENGTH];

    cout<<"Please enter your PIN according to the following mapping"<<endl;
    cout<<"PIN: ";
    
    //prints PIN
    for (int i = 0; i < LENGTH_OF_ALL_USABLE_DIGITS; i++){
        cout<<allUsableDigits[i]<<" ";
    }
    cout<<endl;
    cout<<"NUM: ";
    
    //prints different sequence of number each time
    generateUniqueSequence(uniqueSequence, 10);
    for (int i = 0; i < LENGTH_OF_ALL_USABLE_DIGITS; i++){
        cout<<uniqueSequence[i]<<" ";
    }
    cout<<endl;
    cin>>userInput;
    
    //converts userinput to an array with 5 elements
    while (userInput>0){
        currDigit = userInput % 10;
        for (int i = PASSWORD_LENGTH - 1; i >= 0; i--){
            userEnteredSequence[i] = currDigit;
            userInput /= 10;
            currDigit = userInput % 10;
        }
    }

    findIndicesToCheck(allUsableDigits, PASSWORD, indicesToCheck);
    if (isPasswordMatch(allUsableDigits, userEnteredSequence, indicesToCheck)){
        cout<<"The PIN is correct";
    }
    else{
        cout<<"The PIN is incorrect";
    }

}

void generateUniqueSequence(int arr[], int sizeArr){

    int permissibleValues[3] = {1,2,3};

    for(int i = 0; i < sizeArr; i++){
        arr[i] = permissibleValues[rand() % 3];
    }
}

void findIndicesToCheck(int permissibleDigitsArray[], int constantPassword, int indicesToCheck[]){
    int currentDigit;
    while (constantPassword>0){
        currentDigit = constantPassword % 10;
        for (int i = 0; i < LENGTH_OF_ALL_USABLE_DIGITS; i++){
            if (permissibleDigitsArray[i] == currentDigit){
                indicesToCheck[PASSWORD_LENGTH - (i+1)] = i;
            }
        constantPassword /= 10;
        }
    }
}

bool isPasswordMatch(int permissibleDigitsArray[], int userInputArray[], int indicesToCheck[]){

    int passwordMatch = 1;
    
    for (int i = 0; i < PASSWORD_LENGTH; i++){
        if (permissibleDigitsArray[indicesToCheck[i]] != userInputArray[i]){
            passwordMatch = 0;
            break;
        }
    }

    return (passwordMatch == 1);
}