#include <iostream>
using namespace std;

class DayOfYear
{
public:
    void input();
    void output();
    int month;
    int day;
};

void DayOfYear::input(){
    cout<<"Enter month: ";
    cin>>month;
    cout<<"Enter day: ";
    cin>>day;
}