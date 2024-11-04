#include <iostream>
using namespace std;

int main()
{
    int numOfStudents, count, curr, sum;
    double average;

    cout<<"Enter the number of students: "<<endl;
    cin>>numOfStudents;

    cout<<"Enter the students' grades (seperated by a space): "<<endl;

    sum = 0;
    for (count = 1; count <= numOfStudents; count++)
    {
        cin>>curr;
        sum += curr;
    }
    
    average = (double)sum/(double)numOfStudents;

    cout<<"The average is "<<average<<endl;
    
    return 0;
}
