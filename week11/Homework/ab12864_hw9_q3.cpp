#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int main(){

    //base array
    int baseArr[6] = {3,-1,-3,0,6,4};

    //integers
    int baseArrSize = 6;
    int posArrSize = 0;
    
    //pointers
    int* baseArrPtr = baseArr;
    int* posArrSizePtr = &posArrSize;
    int* posArrPtr;

    
    //main testing func1
    cout<<"Using getPosNums1"<<endl;
    posArrPtr = getPosNums1(baseArrPtr, baseArrSize, posArrSize);
    cout<<"Base address of positive array: "<<posArrPtr<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < posArrSize; i++){
        cout<<*(posArrPtr+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<posArrSize<<endl;
    delete [] posArrPtr;
    posArrPtr = nullptr;
    cout<<endl;

    //main testing func2
    cout<<"Using getPosNums2"<<endl;
    posArrPtr = getPosNums2(baseArrPtr, baseArrSize, posArrSizePtr);
    cout<<"Base address of positive array: "<<posArrPtr<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < (*posArrSizePtr); i++){
        cout<<*(posArrPtr+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<(*posArrSizePtr)<<endl;
    delete [] posArrPtr;
    posArrPtr = nullptr;
    cout<<endl;

    //main testing func3
    cout<<"Using getPosNums3"<<endl;
    getPosNums3(baseArrPtr, baseArrSize, posArrPtr, posArrSize);
    cout<<"Base address of positive array: "<<posArrPtr<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < posArrSize; i++){
        cout<<*(posArrPtr+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<(*posArrSizePtr)<<endl;
    delete [] posArrPtr;
    posArrPtr = nullptr;
    cout<<endl;

    //main testing func4
    int** posArrPtrToPtr = &posArrPtr;
    cout<<"Using getPosNums4"<<endl;
    getPosNums4(baseArrPtr, baseArrSize, posArrPtrToPtr, posArrSizePtr);
    cout<<"Base address of positive array: "<<posArrPtr<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < (*posArrSizePtr); i++){
        //cout<<i<<endl;
        cout<<*(posArrPtr+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<(*posArrSizePtr)<<endl;
    delete [] posArrPtr;
    posArrPtr = nullptr;

    return 0;
}

//Function 1
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            outPosArrSize++;
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

//Function 2
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    *outPosArrSizePtr = 0;
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            (*outPosArrSizePtr)++;
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

//Function 3
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    outPosArrSize = 0;
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            outPosArrSize++;
        }
    }
    if (outPosArr != nullptr) {
        delete[] outPosArr;
        outPosArr = nullptr;
    }
    outPosArr = new int[outPosArrSize];
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            *(outPosArr+k) = *(arr+i);
            k++;
        }
    }
}

//Function 4
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    *outPosArrSizePtr= 0;
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            (*outPosArrSizePtr)++;
        }
    }
    int* temp = new int[(*outPosArrSizePtr)];
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            *(temp+k) = *(arr+i);
            k++;
        }
    }
    *outPosArrPtr = temp;
}