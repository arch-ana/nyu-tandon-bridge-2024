#include <iostream> //Allows us to use cout and cin
#include <cmath> //Allows us to use a math library with predefined constant for PI
using namespace std;

const double PI = 3.14; //We can use this if we do not want to use the cmath library

int main()
{
    double radius, area; //will hold the radius and area entered by user

    cout<<"Please enter the radius: "<<endl;
    cin>>radius;
    
    area = M_PI * radius * radius;

    cout<<"The area of a circle with radius " <<radius<< " is "<<area<<endl;

    return 0;
}