#include <iostream>
using namespace std;

const int ARRAY_SIZE = 6, RANGE = 100;

int cost(int arr[], int arrSize);
int* randArray(int arrSize, int range);
int main(){

    int* arr = randArray(ARRAY_SIZE, RANGE);
    cout<<"Cost of entering each column in order: ";
    for (int i = 0; i<ARRAY_SIZE; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int leastCost = cost(arr, ARRAY_SIZE);
    cout<<"Least cost for the game: "<<leastCost<<endl;

    delete [] arr;
    return 0;
}

int* randArray(int arrSize, int range){
    srand(time(0));
    int* arr = new int[arrSize];
    arr[0] = 0;
    for (int i = 1; i < arrSize; i++){
        arr[i] = rand()%(range+1);
    }

    return arr;
}

int cost(int arr[], int arrSize){
    //at each step, the question is where we wish to jump to the next;
    //or the one after
    if (arrSize <= 3){
        return arr[arrSize-1];
    }
    else{
        int curr = cost(arr, arrSize-1);
        if (curr+arr[arrSize-2] < curr+arr[arrSize-1]){
            curr += arr[arrSize-2];
            return curr;
        }
        else{
            return curr += arr[arrSize-1];
        }
    }
}
