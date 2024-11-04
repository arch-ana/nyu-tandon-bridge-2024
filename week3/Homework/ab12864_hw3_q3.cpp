#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a,b,c,x,y, discriminant;

    cout<<"Please enter a real number value for a: ";
    cin>>a;
    cout<<"Please enter a real number value for b: ";
    cin>>b;
    cout<<"Please enter a real number value for c: ";
    cin>>c;

    //Using the if and else=if blocks, we address cases where user enters values of a b and c
    //that do not make a quadratic equation. This happens when the coefficient of x^2 = 0 while b and c vary. 
    
    //When a = 0 and b = c = 0, the equation has infinite solutions
    if (a == 0 && b == 0 && c == 0){
        cout<<"The equation has infinite solutions"<<endl;
    }
    //When a = 0 and, b = 0 but c !=0, the equation has no solutions
    else if (a == 0 && b == 0 && c != 0){
        cout<<"The equation has no solutions"<<endl;
    }
    //When a = 0 and, b != 0 and c =0, we have the case of a linear equation passing through the origin. This has one solution.  
    else if (a == 0 && b != 0 && c == 0){
        x = 0;
        cout<<"The equation is linear with one solution, x = 0"<<endl;
    }
    else{

        //Else block covers cases where we have values of a,b,c such that we have a quadratic equation. 

        //The discriminant of a quadratic is (b^2-4ac)
        //The value of the discriminant helps us determine the number of solutions an equation has. 
        //Discriminant < 0, no real solutions, discriminant > 0, two real solutions and 
        //discriminant = 0, indicates one solution or two real and equal solutions. 
        discriminant = (b*b - 4*a*c);
        
        if (discriminant > 0){
            x = (-b + sqrt(discriminant))/(2*a);
            y = (-b - sqrt(discriminant))/(2*a);
            
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(1);
            cout<<"The equation has two real solutions, x = "<<x<<" and y = "<<y<<endl;
        }
        
        else if (discriminant == 0){
            x = (-b/2*a);
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(1);
            cout<<"The equation has one real solution, x = "<<x<<endl;
        }
         
        else{
            cout<<"The equation has no real solutions"<<endl;
        }
    }

    return 0;
}