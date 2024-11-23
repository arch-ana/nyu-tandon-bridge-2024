#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();
void resizeArray(int*& arr, int &currArrSize, int newArrSize);
int* findNumDynArray(int* arr, int arrSize, int& resultArrSize, int n);
vector<int> findNumVector(vector<int> userVector, int n);

int main(){

    cout<<"Version 1\n";
    main1();
    cout<<"Version 2\n";
    main2();

    return 0;
}

//main 1
void main1(){

    int currInputSize = 10, currInput, linesArrSize = 0, index=0, searchNum;
    int* userArr = new int [currInputSize];

    cout<<"Please enter a seq of positive integers, each in a separate line.";
    cout<<"End your input by typing -1."<<endl;

    bool reachEnd = false;
    while (reachEnd == false){
        cin>>currInput;
        if (currInput != -1){
            userArr[index++] = currInput;
            if (index == currInputSize){
                resizeArray(userArr, currInputSize, currInputSize*2);
            }
        }
        else{
            reachEnd = true;
        }
    }

    cout<<"Please enter a number you wish to search: ";
    cin>>searchNum;

    int* linesArr = findNumDynArray(userArr, index, linesArrSize, searchNum);
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
    delete [] userArr;
    userArr = nullptr;
}

//main2
void main2(){

    int currInput, searchNum;
    vector <int> userVector;
    vector <int> linesVector;

    cout<<"Please enter a seq of positive integers, each in a separate line.";
    cout<<"End your input by typing -1."<<endl;

    bool reachEnd = false;
    while (reachEnd == false){
        cin>>currInput;
        if (currInput != -1){
            userVector.push_back(currInput);
        }
        else{
            reachEnd = true;
        }
    }

    cout<<"Please enter a number you wish to search: ";
    cin>>searchNum;

    linesVector = findNumVector(userVector, searchNum);
    cout<<"Using vectors, "<<searchNum<<" shows in lines ";
    for (unsigned int i = 0; i < linesVector.size(); i++){
        if(i < linesVector.size() - 1){
            cout<<linesVector[i]<<", ";
        }
        else{
            cout<<linesVector[i];
        }
    }
}

//functions
int* findNumDynArray(int* arr, int actualArrSize, int& resultArrSize, int n){

    int index = 0;
    int* resultArr = new int[actualArrSize];

    for (int i = 0; i < actualArrSize; i++){
        if(arr[i] == n){
            resultArr[index++] = i+1;
            resultArrSize += 1;
        }
    }

    return resultArr;
}

vector<int> findNumVector(const vector<int> userVector, int n){

    vector<int> foundLines;

    for (unsigned int i = 0; i < userVector.size(); i++){
        if(userVector[i] == n){
            foundLines.push_back(i+1);
        }
    }
    return foundLines;
}

void resizeArray(int*& arr, int &currArrSize, int newArrSize){
    int* temp = new int[newArrSize];

    for (int i = 0; i < currArrSize; i++){
        temp[i] = arr[i];
    }

    delete [] arr;
    arr = temp;
    currArrSize = newArrSize;
}