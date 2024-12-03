#include <iostream>
using namespace std;

bool areAllEven(int arr[], int n);
int main(){

    int arr[4] = {2,20,46,14};
    if (areAllEven(arr,4)){
        cout<<"All even"<<endl;
    }
    else{
        cout<<"Not all even"<<endl;
    }
    
    int arr2[4] = {2,1,46,14};
    if (areAllEven(arr2,4)){
        cout<<"All even"<<endl;
    }
    else{
        cout<<"Not all even"<<endl;
    }

    return 0;
}
bool areAllEven(int arr[], int n){
    bool res;
    if (n == 1){
        return (arr[0]%2 == 0);
    }
    else{
        res = areAllEven(arr, n-1);
        if (res == true){
            return(arr[n-1]%2==0);
        }
        else{
            return false;
        }
    }
}
