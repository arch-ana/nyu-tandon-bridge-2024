#include <iostream>
using namespace std;

void moveZeroes(int arr[], int arrSize);
int main(){

	int arr[5] = {0,2,0,1,0};
	int arrSize = 5;

	cout<<"Base array is: ";
	for (int i = 0; i < arrSize; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	moveZeroes(arr, arrSize);

	cout<<"Sorted array is: "; 
	for (int i = 0; i < arrSize; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
		

	return 0;
}

void moveZeroes(int arr[], int arrSize){

	int index = 0;
	
	for (int i = 0; i < arrSize; i++){
		if (arr[i] != 0){
			arr[index] = arr[i];
			if (index != i){
				arr[i] = 0;
			}
			index += 1;
		}
	}
}