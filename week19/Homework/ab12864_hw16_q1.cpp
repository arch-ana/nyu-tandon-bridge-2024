#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

const char LEFT_BRACKET = '(', RIGHT_BRACKET = ')';
const char LEFT_CURLY_BRACE = '{', RIGHT_CURLY_BRACE ='}';
const char LEFT_SQUARE_BRACE = '[', RIGHT_SQUARE_BRACE = ']';

bool symbolBalance(stack<char>& theStack, istream& theStream);

int main(){
    stack <char> charStack;
    string inFileName;
    ifstream inStream; 
    bool symbolBalanced;

    cout<<"Enter the file name: \n";
    cin>>inFileName;

    inStream.open(inFileName);
    inStream.setf(ios::fixed);
    if (inStream.fail()){
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    cout<<"File opened\n";
    
    symbolBalanced = symbolBalance(charStack, inStream);

    if (symbolBalanced == true){
        cout<<"Symbols are in order\n";
    }
    else{
        cout<<"Symbols are not in order\n";
    }

    inStream.close();

    return 0;
}

bool symbolBalance(stack<char>& theStack, istream& theStream){

    cout<<"Enters function\n";

    char currChar;
    string currString, beginString;
    bool hasBegun = false, hasEnded = false;

    while (theStream>>currChar){
        if (currChar == 'b'){
            theStream >> currChar;
            if (currChar == 'e'){
                theStream >> currChar;
                if (currChar == 'g'){
                    theStream >> currChar;
                    if (currChar == 'i'){
                        theStream >> currChar;
                        if (currChar == 'n'){
                            cout<<"Has begun\n";
                            hasBegun = true;
                            //break;
                        }
                    }
                }
            }
        }
        if (currChar == 'e'){
            theStream>>currChar;
            if (currChar == 'n'){
                theStream>>currChar;
                if (currChar == 'd'){
                    cout<<"Has ended\n";
                    hasEnded = true;
                }
            }
        }
        if (hasBegun && !hasEnded){
            if (currChar == LEFT_BRACKET || currChar == LEFT_CURLY_BRACE || currChar == LEFT_SQUARE_BRACE){
                theStack.push(currChar);
                cout<<"It is a left bracket\n";
            }
            else if (currChar == RIGHT_BRACKET){
                if (!theStack.empty() && theStack.top() == LEFT_BRACKET){
                    theStack.pop();
                    cout<<"Popped left bracket\n";
                }
                else{
                    cout<<"No left bracket\n";
                    return false;
                }
            }
            else if (currChar == RIGHT_CURLY_BRACE){
                if (!theStack.empty() && theStack.top() == LEFT_CURLY_BRACE){
                    theStack.pop();
                    cout<<"Popped left curly bracket\n";
                }
                else{
                    cout<<"No left curly bracket\n";
                    return false;
                }
            }
            else if (currChar == RIGHT_SQUARE_BRACE){
                if (!theStack.empty() && theStack.top() == LEFT_SQUARE_BRACE){
                    theStack.pop();
                    cout<<"Popped left square bracket\n";
                }
                else{
                    cout<<"No left square bracket\n";
                    return false;
                }
            }
        }
    }

    // if (!hasBegun){
    //     cout<<"File never began\n";
    //     return false;
    // }

    // while (theStream>>currString){
    //     if (currString == "begin"){
    //         cout<<"Has begun\n";
    //         hasBegun = true;
    //     }
    //     else if (currString == "end"){
    //         hasEnded = true;
    //         cout<<"Has ended\n";
    //     }
    //     else{
    //         if (hasBegun && !hasEnded){
    //             for (int i = 0; i < currString.size(); i++){
    //             currChar = currString[i];
    //                 if (currChar == LEFT_BRACKET || currChar == LEFT_CURLY_BRACE || currChar == LEFT_SQUARE_BRACE){
    //                     theStack.push(currChar);
    //                     cout<<"It is a left bracket\n";
    //                 }
    //                 else if (currChar == RIGHT_BRACKET){
    //                     if (!theStack.empty() && theStack.top() == LEFT_BRACKET){
    //                         theStack.pop();
    //                         cout<<"Popped left bracket\n";
    //                     }
    //                     else{
    //                         cout<<"No left bracket\n";
    //                         return false;
    //                     }
    //                 }
    //                 else if (currChar == RIGHT_CURLY_BRACE){
    //                     if (!theStack.empty() && theStack.top() == LEFT_CURLY_BRACE){
    //                         theStack.pop();
    //                         cout<<"Popped left curly bracket\n";
    //                     }
    //                     else{
    //                         cout<<"No left curly bracket\n";
    //                         return false;
    //                     }
    //                 }
    //                 else if (currChar == RIGHT_SQUARE_BRACE){
    //                     if (!theStack.empty() && theStack.top() == LEFT_SQUARE_BRACE){
    //                         theStack.pop();
    //                         cout<<"Popped left square bracket\n";
    //                     }
    //                     else{
    //                         cout<<"No left square bracket\n";
    //                         return false;
    //                     }
    //                 }
    //             }
    //         }
    //     } 
    // }
    if (!hasBegun && hasEnded){
        cout<<"File ended without beginning\n";
        return false;
    }
    else if (hasBegun && !hasEnded){
        cout<<"File began but has not ended\n";
        return false;
    }
    else if(!hasBegun && !hasEnded){
        cout<<"File neither began nor ended\n";
        return false;
    }
    else{
        cout<<"File began and ended correctly\n";
        return (theStack.empty());
    }
}