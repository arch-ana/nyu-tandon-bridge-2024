#include <iostream>
#include <vector>
using namespace std;

int* main1(int* arr, int arrSize, int n, int& lines);

vector<int> main2(int* arr, int arrSize, int n);

int main(){

    int seqSize = 0, curr, index = 0, searchNum, linesArrSize = 0;
    int* userSeq = new int[seqSize];
    int* linesArr;

    cout<<"Please enter a seq of positive integers, each in a separate line.";
    cout<<"End your input by typing -1."<<endl;
    bool reachEnd = false;

    while (reachEnd == false){
        cin>>curr;
        if (curr != -1){
            seqSize += 1;
            userSeq[index] = curr;
            index++;
        }
        else{
            reachEnd = true;
        }
    }

    cout<<"Please enter a number you wish to search: ";
    cin>>searchNum;

    linesArr = main1(userSeq, seqSize, searchNum, linesArrSize);
    cout<<"Without using vectors, "<<searchNum<<" shows in lines ";
    for (int i = 0; i < linesArrSize; i++){
        if(i < linesArrSize - 1){
            cout<<linesArr[i]<<", ";
        }
        else{
            cout<<linesArr[i];
        }
    }
    cout<<endl;
    delete [] linesArr;
    linesArr = nullptr;


    vector <int> linesVector = main2(userSeq, seqSize, searchNum);
    cout<<"Using vectors, "<<searchNum<<" shows in lines ";
    for (unsigned int i = 0; i < linesVector.size(); i++){
        if(i < linesVector.size() - 1){
            cout<<linesVector[i]<<", ";
        }
        else{
            cout<<linesVector[i];
        }
    }

    delete [] userSeq;
    userSeq = nullptr;

    return 0;
}

int* main1(int* arr, int arrSize, int n, int& lines){

    int* arrLines = new int[arrSize];
    int index = 0;

    for (int i = 0; i < arrSize; i++){
        if(arr[i] == n){
            arrLines[index] = i+1;
            index += 1;
            lines += 1;
        }
    }

    return arrLines;
}

vector<int> main2(int* arr, int arrSize, int n){

    vector<int> arrLines;

    for (unsigned int i = 0; i < arrSize; i++){
        if(arr[i] == n){
            arrLines.push_back(i+1);
        }
    }
    return arrLines;
}