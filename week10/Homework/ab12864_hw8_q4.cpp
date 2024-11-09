#include<iostream>
using namespace std;

int const PASSWORD = 74619;
int const PASSWORD_LENGTH = 5;
int const LENGTH_OF_ALL_USABLE_DIGITS = 10;

void generateUniqueSequence(int arr[], int sizeArr);
void findIndicesToCheck(int permissibleDigitsArray[], int constantPassword, int indicesToCheck[]);
bool isPasswordMatch(int uniqueSequence[], int userInputArray[], int indicesToCheck[]);

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
    
    //converts userinput to an array with 5 elements - debugged
    while (userInput>0){
        currDigit = userInput % 10;
        for (int i = PASSWORD_LENGTH - 1; i >= 0; i--){
            userEnteredSequence[i] = currDigit;
            userInput /= 10;
            currDigit = userInput % 10;
        }
    }

    findIndicesToCheck(allUsableDigits, PASSWORD, indicesToCheck);
    if (isPasswordMatch(uniqueSequence, userEnteredSequence, indicesToCheck)){
        cout<<"The PIN is correct";
    }
    else{
        cout<<"The PIN is incorrect";
    }

}

//function takes an array and its length and modifies the array to contain
//random values between 1 3 and 3. 
void generateUniqueSequence(int arr[], int sizeArr){

    int permissibleValues[3] = {1,2,3};

    for(int i = 0; i < sizeArr; i++){
        arr[i] = permissibleValues[rand() % 3];
    }
}

//this function takes three arguments: 1) an array containing all permissible characters in the password
//2) the actual password of the user and 3) an empty array to hold the indices that need to be checked
//to authenticate the person's password against the randomized array
void findIndicesToCheck(int permissibleDigitsArray[], int constantPassword, int indicesToCheck[]){
    int currentDigit;
    int k = PASSWORD_LENGTH - 1;
    while (constantPassword>0){
        currentDigit = constantPassword % 10;
        for (int i = 0; i < LENGTH_OF_ALL_USABLE_DIGITS; i++){
            if (permissibleDigitsArray[i] == currentDigit){
                indicesToCheck[k] = i;
            }
        }
        constantPassword /= 10;
        k -= 1;
    }
}

//function checks if the person's response matches with their actual password 
bool isPasswordMatch(int uniqueSequence[], int userInputArray[], int indicesToCheck[]){

    int passwordMatch = 1;
    
    for (int i = 0; i < PASSWORD_LENGTH; i++){
        if (uniqueSequence[indicesToCheck[i]] != userInputArray[i]){
            passwordMatch = 0;
        }
    }

    return (passwordMatch == 1);
}