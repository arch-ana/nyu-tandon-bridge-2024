#include <iostream>
using namespace std;

void oddKeepEvensFlip(int arr[], int arrSize);
int main(){

    int arr[6] = {5,2,11,7,6,4};
    cout<<"Base array"<<endl;
    for (int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    oddKeepEvensFlip(arr, 6);
    cout<<"Reordered array"<<endl;
    for (int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void oddKeepEvensFlip(int arr[], int arrSize){
    int *arrOdd = new int[arrSize], *arrEven = new int[arrSize], arrOddSize = 0, arrEvenSize = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i]%2 != 0){
            arrOdd[arrOddSize] = arr[i];
            arrOddSize++;
        }
        else{
            arrEven[arrEvenSize] = arr[i];
            arrEvenSize++;
        }
    }

    for (int i = 0; i<arrOddSize; i++){
        arr[i] = arrOdd[i];
    }
    int k = 0;
    for (int i = arrSize-1; i>=arrOddSize; i--){
        arr[i] = arrEven[k];
        k++;
    }
    delete [] arrEven;
    delete [] arrOdd; 
}
