//Implement a function that returns the minimum value in an array
//Use it in a program that interacts with the user to accept a 20-character long array

#include <iostream>
using namespace std;

const int ARRAY_LENGTH = 20;
int minInArray (int arr[], int arrSize);
int indiceOfValueinArray(int valueToCheck, int indiceToCheck, int arr[], int arrSize);
int main()
{
    int userInput;
    int userArray[ARRAY_LENGTH];
    int indiceArray[ARRAY_LENGTH];

    cout<<"Please enter 20 integers seperated by a space: \n";

    for (int i = 0; i<ARRAY_LENGTH; i++)
    {
        cin>>userInput;
        userArray[i] = userInput;
    }

    int minimumValueInArray = minInArray(userArray, ARRAY_LENGTH);

    cout<<"The min is "<<minimumValueInArray<<", and it is located in the following indices: ";
    for (int j = 0; j < ARRAY_LENGTH; j++)
    {
        int indice = indiceOfValueinArray(minimumValueInArray, j, userArray, ARRAY_LENGTH);
        if (indice != -1)
        {
            cout<<indice<<" ";
        }
    }

}

//function accepts an array and the length of the array
//and returns the minimum value in the array
int minInArray(int arr[], int arrSize)
{
    int minValue = arr[0];
    
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }

    return minValue;
}

//function accepts an integer input and an array, locates the indices within
//the array where the integer is located. calls a new array by reference
//and modifies it to include all these indices

int indiceOfValueinArray(int valueToCheck, int indiceToCheck, int arr[], int arrSize)
{
    int nextIndice = -1;

    if (arr[indiceToCheck] == valueToCheck)
    {
        nextIndice = indiceToCheck;
    }

    return nextIndice;
}