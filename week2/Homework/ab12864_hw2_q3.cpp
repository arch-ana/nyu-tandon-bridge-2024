#include <iostream>
using namespace std;

int main()
{
    int johnDays, johnHours, johnMinutes, billDays, billHours, billMinutes, totalDays, totalHours, totalMinutes;

    cout<<"Please enter the number of days John has worked: "<<endl;
    cin>>johnDays;
    cout<<"Please enter the number of hours John has worked: "<<endl;
    cin>>johnHours;
    cout<<"Please enter the number of minutes John has worked: "<<endl;
    cin>>johnMinutes;
    cout<<"\n"<<endl;
    cout<<"Please enter the number of days Bill has worked: "<<endl;
    cin>>billDays;
    cout<<"Please enter the number of hours Bill has worked: "<<endl;
    cin>>billHours;
    cout<<"Please enter the number of minutes Bill has worked: "<<endl;
    cin>>billMinutes;
    cout<<"\n"<<endl;

    totalDays = johnDays + billDays + ((johnHours+billHours)/24) + ((johnMinutes+billMinutes)/(60*24));

    totalHours = ((johnHours + billHours) % 24) + (johnMinutes+billMinutes)/60;

    totalMinutes = (johnMinutes + billMinutes) % 60;
    
    cout<<"The total time both of them worked together is "<<totalDays<<" days, "<<totalHours<<" hours "<<totalMinutes<<" minutes."<<endl;

    return 0;
}