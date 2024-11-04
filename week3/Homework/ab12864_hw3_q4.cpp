#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

    int roundingMethod, integerPart, roundedNumber;
    double realNumber, fractionalPart;

    cout<<"Please enter a Real number: "<<endl;
    cin>>realNumber;
    cout<<"Choose your rounding method: \n 1. Floor round \n 2. Ceiling round \n 3. Round to the nearest whole number"<<endl;
    cin>>roundingMethod;

    integerPart = int(realNumber);
    fractionalPart = double(realNumber - integerPart);

    //When real number entered by the user is an integer
    //the rounded off number is the integer itself. 
    if (fractionalPart == 0){
        roundedNumber = realNumber;
    }
    //Case where the real number is not an integer and is negative.
    else if (fractionalPart < 0){

        switch (roundingMethod){
            case FLOOR_ROUND:
                roundedNumber = integerPart -1;
                break;

            case CEILING_ROUND:
                roundedNumber = integerPart;
                break;

            case ROUND:
                if (fractionalPart > -0.5){
                    roundedNumber = integerPart;
                }
                else{
                    roundedNumber = integerPart - 1;
                }
                break;
        }
    }
    //Case where the real number is not an integer and is positive.
    else{
        switch (roundingMethod){
            case FLOOR_ROUND:
                roundedNumber = integerPart;
                break;

            case CEILING_ROUND:
                roundedNumber = integerPart + 1;
                break;

            case ROUND:
                if (fractionalPart >= 0.5){
                    roundedNumber = integerPart + 1;
                }
                else{
                    roundedNumber = integerPart;
                }
                break;
        }
    }

    cout<<roundedNumber<<endl;
    
    return 0;
}