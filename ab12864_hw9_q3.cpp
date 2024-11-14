#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int main(){

    int arr1[6] = {3,-1,-3,0,6,4};
    int* pointerToOriginalArray = arr1;
    int arrSize1 = 6;
    int outPosArrSize = 0;
    
    cout<<"Pointer to array "<<pointerToOriginalArray<<endl;
    int *baseAddressPosArray = getPosNums1(pointerToOriginalArray, arrSize1, outPosArrSize);
    cout<<"Base address of positive array: "<<baseAddressPosArray<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < outPosArrSize; i++){
        cout<<*(baseAddressPosArray+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<outPosArrSize;
    delete [] baseAddressPosArray;

    return 0;
}
//input
// 1)pointer to an array
// 2)size of the array
// 3)reference to a variable that holds the size of array 
//  with positive elements

// output: returns the base address of the array containing the positive numbers
//and updates the output parameter outPosArrSize with the array's logical size
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            cout<<"in if: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
            *(arr+k) = *(arr+i);
            k++;
            outPosArrSize++;
        }
        else{
            cout<<"in else: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
        }
    }
    int* ptrPosArr = new int[outPosArrSize];
    for (int i = 0; i<outPosArrSize; i++){
        *(ptrPosArr+i) = *(arr+i);
    }
    return ptrPosArr;
}