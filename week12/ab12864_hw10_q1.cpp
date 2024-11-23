#include <iostream>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main(){

    string sentence;
    string* wordsInSentence;
    int outWordsArrSize = 0;

    cout<<"Please enter a sentence: ";
    getline(cin, sentence);
    cout<<endl;

    wordsInSentence =  createWordsArray(sentence, outWordsArrSize);

    for (int i = 0; i < outWordsArrSize; i++){
        cout<<wordsInSentence[i]<<" ";
    }
    cout<<endl;
    cout<<"Total number of words in the array is: "<<outWordsArrSize;
    
    delete [] wordsInSentence;
    wordsInSentence = nullptr;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
    
    int start = -1, end = -1, spaces = 0, index = 0;

    for (int i = 0; i < sentence.length(); i++){
        if (sentence[i] == ' '){
            spaces += 1;
        }
    }

    string *stringArray = new string [spaces + 1];

    for (int i = 0; i < sentence.length(); i++){
        if ((int(sentence[i]) >= 97 && int(sentence[i]) <= 122) || (int(sentence[i]) >= 65 && int(sentence[i]) <= 90)){
            if (i == 0 || sentence[i-1] == ' ' ){
                start = i;
            }
            if (i == sentence.length()-1 || sentence[i+1] == ' ' ){
                end = i;
            }
        }
        if (start != -1 && end != -1){
            outWordsArrSize += 1;
            stringArray[index] = sentence.substr(start, end - start +1);
            index+=1;
            start = -1;
            end = -1;
        }
    }
    return stringArray;
}