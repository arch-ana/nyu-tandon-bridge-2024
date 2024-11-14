#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int main(){

    int arr1[6] = {3,-1,-3,0,6,4};
    int* arrPtr = arr1;
    int arrSize1 = 6;
    int outPosArrSize = 0;
    int* posArrSizePtr = &outPosArrSize;
    
    cout<<"USING FUNC1"<<endl;
    cout<<"Base address of original array "<<arrPtr<<endl;
    int *baseAddressPosArray1 = getPosNums1(arrPtr, arrSize1, outPosArrSize);
    cout<<"Base address of positive array: "<<baseAddressPosArray1<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < outPosArrSize; i++){
        cout<<*(baseAddressPosArray1+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<outPosArrSize<<endl;
    delete [] baseAddressPosArray1;

    cout<<"Original array after func1 is: ";
    for (int i = 0; i<arrSize1; i++){
        cout<<arr1[i]<<" ";
        }
    cout<<endl;

    cout<<"USING FUNC2"<<endl;
    *posArrSizePtr = 0;
    cout<<"Base address of original array "<<arrPtr<<endl;
    int *baseAddressPosArray2 = getPosNums2(arrPtr, arrSize1, posArrSizePtr);
    cout<<"Base address of positive array: "<<baseAddressPosArray2<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < (*posArrSizePtr); i++){
        cout<<*(baseAddressPosArray2+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<(*posArrSizePtr)<<endl;
    delete [] baseAddressPosArray2;

    cout<<"Original array after func1 is: ";
    for (int i = 0; i<arrSize1; i++){
        cout<<arr1[i]<<" ";
        }
    cout<<endl;

    return 0;
}
//input 1)pointer to an array 2)size of the array 3)reference to a variable that holds the size of the new array with positive elements
//output 1) returns the base address of the new array containing positive integers 2) updates the output parameter 
//outPosArrSize with the array's size
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            cout<<"in if: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
            outPosArrSize++;
        }
        else{
            cout<<"in else: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
        }
    }
    int* posArrPtr = new int[outPosArrSize];
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            *(posArrPtr+k) = *(arr+i);
            k++;
        }
    }
    return posArrPtr;
}

//input 1) pointer to base of address of an array 2) size of the array 3) pointer to an integer variable
//output 1) returns the base address of the new array containing positive integers 2) uses pointer outPosArrSizePtr to update array's logical size
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            cout<<"in if: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
            (*outPosArrSizePtr)++;
        }
        else{
            cout<<"in else: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
        }
    }
    int* posArrPtr = new int[*outPosArrSizePtr];
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            *(posArrPtr+k) = *(arr+i);
            k++;
        }
    }
    return posArrPtr;
}