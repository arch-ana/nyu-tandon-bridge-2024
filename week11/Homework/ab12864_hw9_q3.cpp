#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int main(){

    int baseArr[6] = {3,-1,-3,0,6,4};
    int* baseArrPtr = baseArr;
    int baseArrSize = 6;
    int outPosArrSize = 0;
    int* posArrSizePtr = &outPosArrSize;
    
    cout<<"USING FUNC1"<<endl;
    cout<<"Base address of original array "<<baseArrPtr<<endl;
    int *baseAddressPosArray1 = getPosNums1(baseArrPtr, baseArrSize, outPosArrSize);
    cout<<"Base address of positive array: "<<baseAddressPosArray1<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < outPosArrSize; i++){
        cout<<*(baseAddressPosArray1+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<outPosArrSize<<endl;
    delete [] baseAddressPosArray1;
    baseAddressPosArray1 = nullptr;

    cout<<"Original array after func1 is: ";
    for (int i = 0; i<baseArrSize; i++){
        cout<<baseArr[i]<<" ";
        }
    cout<<endl;

    //----------------------------------------

    cout<<"USING FUNC2"<<endl;
    *posArrSizePtr = 0;
    cout<<"Base address of original array "<<baseArrPtr<<endl;
    int *baseAddressPosArray2 = getPosNums2(baseArrPtr, baseArrSize, posArrSizePtr);
    cout<<"Base address of positive array: "<<baseAddressPosArray2<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < (*posArrSizePtr); i++){
        cout<<*(baseAddressPosArray2+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<(*posArrSizePtr)<<endl;
    delete [] baseAddressPosArray2;
    baseAddressPosArray2 = nullptr;

    cout<<"Original array after func2 is: ";
    for (int i = 0; i<baseArrSize; i++){
        cout<<baseArr[i]<<" ";
        }
    cout<<endl;

    //----------------------------------------

    cout<<"USING FUNC3"<<endl;
    int posArrSize = 0;
    int* posArrPtr = new int[posArrSize];
    cout<<"Base address of original array "<<baseArrPtr<<endl;
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

    cout<<"Original array after func3 is: ";
    for (int i = 0; i<baseArrSize; i++){
        cout<<baseArr[i]<<" ";
        }
    cout<<endl;

    //----------------------------------------

    cout<<"USING FUNC4"<<endl;
    int* posArrSizePtr4;
    *posArrSizePtr4 = 0;
    //int* posArrPtr4 = new int[*posArrSizePtr4];
    int* posArrPtr4;
    cout<<"Base address of original array "<<baseArrPtr<<endl;
    getPosNums4(baseArrPtr, baseArrSize, &posArrPtr4, posArrSizePtr4);
    cout<<"Base address of positive array: "<<posArrPtr4<<endl;
    cout<<"Array with positive elements: ";
    for (int i = 0; i < (*posArrSizePtr4); i++){
        //cout<<i<<endl;
        cout<<*(posArrPtr4+i)<<" ";
    }
    cout<<endl;
    cout<<"Size of positive array: "<<(*posArrSizePtr4)<<endl;
    delete [] posArrPtr4;
    posArrPtr4 = nullptr;

    cout<<"Original array after func3 is: ";
    for (int i = 0; i<baseArrSize; i++){
        cout<<baseArr[i]<<" ";
        }
    cout<<endl;

    return 0;
}

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

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int k = 0;    
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            cout<<"in if: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
            (outPosArrSize)++;
        }
        else{
            cout<<"in else: "<<endl;
            cout<<"*(arr+i) is: "<<*(arr+i)<<endl;
        }
    }
    outPosArr = new int[outPosArrSize];
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            *(outPosArr+k) = *(arr+i);
            cout<<"test"<<endl;
            cout<<*(outPosArr+k);
            k++;
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
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
    cout<<"check outposarrsizeptr: "<<*outPosArrSizePtr<<endl;

    int* temp = new int[(*outPosArrSizePtr)];
    for (int i = 0; i<arrSize; i++){
        if (*(arr+i) > 0){
            *(temp+k) = *(arr+i);
            cout<<"test "<<endl;
            cout<<*(temp+k)<<endl;
            k++;
        }
    }
    cout<<temp<<endl;
    *outPosArrPtr = temp;
}