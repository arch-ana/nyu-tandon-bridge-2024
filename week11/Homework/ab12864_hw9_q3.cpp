#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int main(){

    int arr1[6] = {3,-1,-3,0,6,4};
    int* pointerToArray = arr1;
    int arrSize1 = 6;
    int outPosArrSize = 0;

    int *sizeOfPositiveArray = getPosNums1(pointerToArray, arrSize1, outPosArrSize);
    cout<<"Address of base of array: "<<sizeOfPositiveArray<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < *sizeOfPositiveArray; i++){
        cout<<*(pointerToArray+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<*sizeOfPositiveArray;

    return 0;
}
//input: 1) pointer to an array 2)size of the array and 3)reference to a variable that holds the 
//size of array with positive elements
//output: returns a pointer pointing to the base address of the array containing positive numbers
//and updates the parameter outPosArrSize with the array's logical size
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            *(arr+k) = *(arr+i);
            k++; 
        }
        else{
            arrSize--;
        }
    }
    outPosArrSize = arrSize;
    return arr;
}


int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);