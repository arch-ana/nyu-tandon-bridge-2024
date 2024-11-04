#include <iostream>
using namespace std;

const int DAYS_IN_A_WEEK =7;

int main()
{
    int totalDays; //will hold the total days travelled
    int fullWeeks; //will hold the full weeks travelled
    int remainingDays; //will hold the remaining days travelled

    cout<<"Please enter number of days you travelled: "<<endl;
    cin>>totalDays;
    
    fullWeeks = totalDays / DAYS_IN_A_WEEK;
    remainingDays = totalDays % DAYS_IN_A_WEEK;

    cout<<"The person has travelled " <<fullWeeks<< " weeks and "<<remainingDays<< " days"<<endl;

    return 0;
}