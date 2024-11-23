#include <iostream>
using namespace std;

const int ARRAY_SIZE = 6;

int* findMissing(int arr[], int n, int& resArrSize);

int main(){

    int resArrSize;
    int* resArr;

    int arr[ARRAY_SIZE] = {3, 1, 3, 0, 6, 4};

    resArr = findMissing(arr, ARRAY_SIZE, resArrSize);
    cout<<"Missing elements array: ";
    for (int i = 0; i < resArrSize; i++){
        cout<<resArr[i]<<" ";
    }
    cout<<endl;
    cout<<"Size of missing elements array: "<<resArrSize<<endl;

    delete [] resArr;
    resArr = nullptr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    
    int* existArray = new int [n+1]();
    int index=0;
    resArrSize = 0;
    
    for (int i = 0; i < n; i++){
        existArray[arr[i]] += 1;
    }

    for (int i = 0; i < n+1; i++){
        if (existArray[i] == 0){
            resArrSize += 1;
        }
    }

    int *resArr = new int[resArrSize];
    for (int i = 0; i <= n; i++) {
        if (existArray[i] == 0) {
            resArr[index++] = i;
        }
    }
    
    delete [] existArray;
    existArray = nullptr;

    return resArr;
}