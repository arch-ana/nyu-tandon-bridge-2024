#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10, RANGE = 15;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);
int* randArray(int arrSize, int range);
int main(){

    int* newArray = randArray(ARRAY_SIZE, RANGE);
    cout<<"Random array is: ";
    for (int i = 0; i< ARRAY_SIZE; i++){
        cout<<newArray[i]<<" ";
    }

    int min = minInArray1(newArray, ARRAY_SIZE);
    cout<<"Minimum by method 1 is: "<<min<<endl;

    int high = rand()%ARRAY_SIZE;
    int low = rand()%ARRAY_SIZE;
    cout<<"High is: "<<high<<" and low is "<<low<<endl;
    int min = minInArray2(newArray, low, high);
    cout<<"Minimum by method 1 is: "<<min<<endl;

    delete [] newArray;
    return 0;
}

//func1
int minInArray1(int arr[], int arrSize){
    if (arrSize == 1){
        return arr[0];
    }
    else{
        minInArray1(arr, arrSize-2);
        if (arr[arrSize-1]<arr[arrSize-2]){
            return arr[arrSize-1];
        }
        else{
            return arr[arrSize-2];
        }

    }
}

//func2
int minInArray2(int arr[], int low, int high){
    if (low == high){
        return arr[low];
    }
    else{
        minInArray2(arr, low, high-1);
        if (arr[high]<minInArray2(arr, low, high-1)){
            return arr[high];
        }
        else{
            return minInArray2(arr, low, high-1);
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

