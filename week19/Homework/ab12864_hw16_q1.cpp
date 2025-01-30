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
    string beginString;

    while (theStream>>currChar){
        if (currChar == 'b'){
            beginString += currChar;
        }
        if (currChar == LEFT_BRACKET || currChar == LEFT_CURLY_BRACE || currChar == LEFT_SQUARE_BRACE){
            theStack.push(currChar);
            cout<<"It is a left bracket\n";
        }
        else if (currChar == RIGHT_BRACKET){
            if (theStack.top() == LEFT_BRACKET){
                theStack.pop();
                cout<<"Popped left bracket\n";
            }
            else{
                cout<<"No left bracket\n";
                return false;
            }
        }
        else if (currChar == RIGHT_CURLY_BRACE){
            if (theStack.top() == LEFT_CURLY_BRACE){
                theStack.pop();
                cout<<"Popped left curly bracket\n";
            }
            else{
                cout<<"No left curly bracket\n";
                return false;
            }
        }
        else if (currChar == RIGHT_SQUARE_BRACE){
            if (theStack.top() == LEFT_SQUARE_BRACE){
                theStack.pop();
                cout<<"Popped left square bracket\n";
            }
            else{
                cout<<"No left square bracket\n";
                return false;
            }
        } 
    }
    return (theStack.empty());
}