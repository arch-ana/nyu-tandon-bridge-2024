#include <iostream>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalendar(int year, int startingDay);
int main()
{
    int userYear, userStartDay;

    cout<<"Please enter a year: ";
    cin>>userYear;
    cout<<"Please enter start day: ";
    cin>>userStartDay;
    cout<<endl;

    printYearCalendar(userYear, userStartDay);

    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay)
{
    int lastDay, numOfTabs;
    char tab = '\t';

    if (startingDay > 0)
    {
        numOfTabs = startingDay - 1;
    }

    cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;
    for (int i = 1; i <= numOfTabs; i++)
    {
        cout<<tab;
    }
    for (int i = 1; i <= numOfDays; i++)
    {
        cout<<i<<tab;
        if ((i + numOfTabs) % 7 == 0)
        {
            cout<<endl;
        }
    }

    int remDays = (numOfDays + numOfTabs) % 7;

    if (remDays == 0)
    {
        lastDay = 7;
    }
    else
    {
        lastDay = remDays;
        cout<<endl;
    }

    return lastDay;
}

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year%100 == 0)
        {
            if (year%400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
void printYearCalendar(int year, int startingDay)
{
    int daysInTheMonth;

    for (int i = 1; i <= 12; i++)
    {
        if (i == 2)
        {
            if (isLeapYear(year))
            {
                daysInTheMonth = 29;
            }
            else
            {
                daysInTheMonth = 28;
            }
        }
        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            daysInTheMonth = 31;
        }
        else
        {
            daysInTheMonth = 30;
        }

        switch (i)
        {
        case 1:
            cout<<"January "<<year<<endl;
            break;
        case 2:
            cout<<"February "<<year<<endl;
            break;
        case 3:
            cout<<"March "<<year<<endl;
            break;
        case 4:
            cout<<"April "<<year<<endl;
            break;
        case 5:
            cout<<"May "<<year<<endl;
            break;
        case 6:
            cout<<"June "<<year<<endl;
            break;
        case 7:
            cout<<"July "<<year<<endl;
            break;
        case 8:
            cout<<"August "<<year<<endl;
            break;
        case 9:
            cout<<"September "<<year<<endl;
            break;
        case 10:
            cout<<"October "<<year<<endl;
            break;
        case 11:
            cout<<"November "<<year<<endl;
            break;
        case 12:
            cout<<"December "<<year<<endl;
            break;
        }

        printMonthCalendar(daysInTheMonth, startingDay);
        startingDay = (startingDay + daysInTheMonth - 1)%7 +1;
        cout<<endl;
    }
    
    
}
