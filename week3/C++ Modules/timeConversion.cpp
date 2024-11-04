// Problem that reads from the users a time entered in a 24-hour format,
// and prints the equivalent time in a 12-hour format.

#include <iostream>
#include <string>

using namespace std;

int main() {

    int inputHour, inputMinutes;
    int outputHour, outputMinutes;
    string period;
    char temp;

    cout<<"Please enter the time in 24-hour format: ";
    cin>>inputHour>>temp>>inputMinutes;

    outputMinutes = inputMinutes;

    if (inputHour >= 0 && inputHour <= 11){
        period = "AM";
        if (inputHour == 0)
            outputHour = 12;
        else
            outputHour = inputHour;
    }
    else{ 
        period = "PM";
        if (inputHour == 12)
            outputHour = 12;
        else
            outputHour = inputHour - 12;
    
    }
    cout<<inputHour<<temp<<inputMinutes<<" in 12-hour format is "<<outputHour<<temp<<outputMinutes<<" "<<period<<endl;

    return 0;
}