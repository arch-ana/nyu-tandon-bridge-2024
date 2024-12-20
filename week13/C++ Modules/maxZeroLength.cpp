#include <iostream>
using namespace std;

int maxZeroLength(int arr[], int arrSize, int x);
int main(){

	int arr[6] = {0,0,1,0,0,0};
	int arrSize = 6;

	int zeroes = maxZeroLength(arr, arrSize, 0);
	cout<<"Number of zeroes is: "<<zeroes;

	return 0;
}

int maxZeroLength(int arr[], int arrSize, int x){

	int max = 0;

	if (arrSize == 1){
		if (arr[0]==x){
			max += 1;
			return max;
		}
		else{
			return max;
		}	
	}
	else{
		maxZeroLength(arr, arrSize-1, x);
		if (arr[arrSize-1] == x){
			max = maxZeroLength(arr, arrSize-1, x)+1;
			return max;
		}
		else{
			return maxZeroLength(arr, arrSize-1, x);
		}
	}
}