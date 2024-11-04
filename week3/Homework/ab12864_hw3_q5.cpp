#include <iostream>
#include <string>
using namespace std;

const double KILOS_IN_POUNDS = 0.453592;
const double METERS_IN_INCHES = 0.0254;

int main() {
    
    double weightPounds, heightInches, weightKilos, heightMeters, bodyMassIndex;
    string weightStatus;

    cout<<"Please enter weight (in pounds): ";
    cin>>weightPounds;
    cout<<"Please enter height (in inches): ";
    cin>>heightInches;

    //Convering weight to KGs and height to meters
    weightKilos = weightPounds*KILOS_IN_POUNDS;
    heightMeters = heightInches*METERS_IN_INCHES;

    //Formula for calculating a person's BMI
    bodyMassIndex = weightKilos/(heightMeters*heightMeters);

    if (bodyMassIndex < 18.5) {
        weightStatus = "Underweight";
    }
    else if (bodyMassIndex >= 18.5 && bodyMassIndex < 25){
        weightStatus = "Normal";
    }
    else if (bodyMassIndex >= 25 && bodyMassIndex < 30) {
        weightStatus = "Overweight";
    }
    else{
        weightStatus = "Obese";
    }

    cout<<"The weight status is: "<<weightStatus<<endl;


    return 0;
}