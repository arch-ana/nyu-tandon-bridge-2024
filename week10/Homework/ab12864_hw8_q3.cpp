#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
int main(){
    int arr1[10] = {9,2,14,12,-3};
    int arr1Size = 5;

    int arr2[10] = {21,12,6,7,14};
    int arr2Size = 5;

    int arr3[10] = {3,6,4,1,12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void reverseArray(int arr[], int arrSize){

    int temp;

    for (int i = 0; i < (arrSize/2); i++){
        temp = arr[i];
        arr[i] = arr[(arrSize-1) - i];
        arr[(arrSize-1) - i] = temp;
    }

}

void removeOdd(int arr[], int& arrSize){
    int k = 0;
    int counter = 0;
    
    for (int i = 0; i<arrSize; i++){
        if (arr[i]%2 == 0){
            arr[k] = arr[i];
        }
        else{
            counter++;
        }
    }
    arrSize -= counter;
}

void splitParity(int arr[], int arrSize){

    int i = 0;
    int j = arrSize-1;
    int temp;

    while (i<j){
        while(i<j && arr[i]%2 != 0){
            i++;
        }
        while(i<j && arr[j]%2 == 0){
            j--;
        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

}

void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i<arrSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}