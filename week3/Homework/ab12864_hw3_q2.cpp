#include <iostream>
#include<string>

using namespace std;

int main() {

    string name;
    int graduationYear, currentYear, yearsLeftToGraduate;

    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>graduationYear;
    cout<<"Please enter current year: ";
    cin>>currentYear;

    //If block for all cases where user enters a graduation year that is in the future; i.e atleast one year ahead. 
    //The switch statement breaks this down further, assuming the default as the case where the years for the graduate is more than 4 years
    //The other cases account for 1,2,3, and 4 years left for graduation, making them a senior, junior, sophomore or freshman.

    if (graduationYear > currentYear){        
        yearsLeftToGraduate = (graduationYear - currentYear);

        switch (yearsLeftToGraduate)
        {
        case 1:
            cout<<name<<", you are a Senior.";
            break;

        case 2:
            cout<<name<<", you are a Junior.";
            break;

        case 3:
            cout<<name<<", you are a Sophomore.";
            break;

        case 4:
            cout<<name<<", you are a Freshman.";
            break;
        
        default:
            cout<<name<<", you are not in college yet.";
            break;
        }
    }
    //Else block for all cases where user enters a graduation year equal to or prior to the current year.
    else{
        cout<<name<<", you have Graduated.";
    }
    
    return 0;
}