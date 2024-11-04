#include <iostream>
#include <string>

using namespace std;

const double WEEKDAY_DAY_TIME_RATE = 0.40;
const double WEEKDAY_NIGHT_TIME_RATE = 0.25;
const double WEEKEND_RATE = 0.15;

int main() {

    string day;
    double startHour, startMinutes, duration, applicableRate, callCost;
    char colon;

    cout<<"Day of the week (Sa, Su, Mo, Tu, We, Th, Fr): ";
    cin>>day;
    cout<<"Time of the day (in 24-hour notation with a colon, ex. 13:20): ";
    cin>>startHour>>colon>>startMinutes;
    cout<<"Duration of call (enter minutes as a positive integer): ";
    cin>>duration;

    //Depending on the day and time of the call, this if-block assigns the 
    //rate that will apply to the call. 
    if (day == "Sa" || day == "Su"){
        applicableRate = WEEKEND_RATE;
    }
    else{
        if (startHour >= 8 && startHour <= 18 && startMinutes <= 0 && startMinutes < 60){
            applicableRate = WEEKDAY_DAY_TIME_RATE;
        }
        else{
            applicableRate = WEEKDAY_NIGHT_TIME_RATE;
        }
    }
    
    //Using the applicable rate, we calculate the total cost of the phone call. 
    callCost = duration*applicableRate;
    
    cout<<"Cost of call is: $"<<callCost<<endl;

    return 0;
}