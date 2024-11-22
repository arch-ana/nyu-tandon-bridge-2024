#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main(){

    int resArrSize = 0, userArrSize, currInput;
    int* resArr;

    cout<<"Enter the size of the array: ";
    cin>>userArrSize;

    int userArr[userArrSize];

    cout<<"Enter elements in array: ";
    for (int i = 0; i < userArrSize; i++){
        cin>>currInput;
        userArr[i] = currInput;
    }

    resArr = findMissing(userArr, userArrSize, resArrSize);
    cout<<"Array of missing elements between 0 and "<<userArrSize<<" is: ";
    for (int i = 0; i < resArrSize; i++){
        cout<<resArr[i]<<" ";
    }
    cout<<endl;
    cout<<"The size of the array of missing elements is: "<<resArrSize<<endl;

    delete [] resArr;
    resArr = nullptr;

    return 0;

}

int* findMissing(int arr[], int n, int& resArrSize){
    
    int existArray[n+1], temp = 0, index=0;
    
    for (int i = 0; i < n+1; i++){
        existArray[i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        temp = arr[i];
        existArray[temp] += 1;
    }

    int *resArr = new int[n+1];

    for (int i = 0; i < n+1; i++){
        if (existArray[i] <= 0){
            resArr[index] = i;
            resArrSize += 1;
            index++;
        }
    }
    return resArr;
}