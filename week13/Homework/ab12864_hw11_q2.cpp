#include <iostream>
#include <time.h>
using namespace std;

//constants
const int ARRAY_SIZE = 5, RANGE = 15;

//function declarations
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
int* randArray(int arrSize, int range);

//main
int main(){

    int* newArray;
    int sum;

    newArray = randArray(ARRAY_SIZE, RANGE);
    cout<<"Random array is: ";
    for (int i = 0; i< ARRAY_SIZE; i++){
        cout<<newArray[i]<<" ";
    }

    sum = sumOfSquares(newArray, ARRAY_SIZE);
    cout<<endl<<"Sum of squares of elements in array is: "<<sum<<endl;
    cout<<"Order of elements: ";
    if (isSorted(newArray, ARRAY_SIZE)){
        cout<<"Ascending";
    }
    else{
        cout<<"Not ascending";
    }

    delete [] newArray;

    return 0;
}

//func1 def
int sumOfSquares(int arr[], int arrSize){
    int sum;
    if (arrSize==1){
        sum = arr[0]*arr[0];
        return sum;
    }
    else{
        sumOfSquares(arr, arrSize-1);
        sum = sumOfSquares(arr, arrSize-1) + arr[arrSize-1]*arr[arrSize-1];
        return sum;
    }
}

//func2 def
bool isSorted(int arr[], int arrSize){
    if (arrSize == 1){
        return true;
    }
    else{
        isSorted(arr, arrSize-1);
        if (isSorted(arr, arrSize-1)){
            return (arr[arrSize-1] > arr[arrSize-2]);
        }
        else{
            return false;
        }
    }
}

//func3 def
int* randArray(int arrSize, int range){
    srand(time(0));

    int* arr = new int[arrSize];

    for (int i = 0; i<arrSize; i++){
        arr[i] = rand()%(RANGE+1) - rand()%(RANGE+1);
    }

    return arr;
}