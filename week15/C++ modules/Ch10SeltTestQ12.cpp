#include <iostream>
using namespace std;

class Temperature
{
public:
    void set(double new_degrees, char new_scale);
    double degrees;
    char scale;
};

void Temperature::set(double new_degrees, char new_scale){
    degrees = new_degrees;
    scale = new_scale;
}