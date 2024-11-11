#include <iostream>
#include <string>
using namespace std;

int main(){

    string temp, firstName, middleName, periodFollowingMiddleName, lastName;

    cout<<"Please enter your name in the format - first name, middle name, last name: ";
    cin>>firstName>>middleName>>lastName;

    if (middleName[1] == '.'){
        cout<<"User, "<<firstName<<" "<<middleName;
    }
    else{
        cout<<"User, "<<firstName<<" "<<middleName[0]<<". ";
    }
    
    return 0;
}