#include <iostream>
using namespace std;

const int MAX_CLASS_SIZE = 60;

int main()
{
    int numOfStudents, currGrade, sum, indArray;
    int gradesList[MAX_CLASS_SIZE];
    double average;

    cout<<"Please enter number of students (no more than "<<MAX_CLASS_SIZE<<")";
    cin>>numOfStudents;

    cout<<"Please enter grades seperated by space: ";
    
    //reading grades
    for (indArray = 0; indArray < numOfStudents; indArray++)
    {
        cin>>currGrade;
        gradesList[indArray] = currGrade;
    }

    //calculate average
    sum = 0;
    for (indArray = 0; indArray<numOfStudents ; indArray++)
    {
        sum += gradesList[indArray];
    }

    average = double(sum)/double(numOfStudents);
    cout<<"Average is: "<<average<<endl;
    
    //print grades above the average
    cout<<"The grades above average are: ";
    for (indArray = 0; indArray < numOfStudents; indArray++)
    {
        if (gradesList[indArray] > average)
        {
            cout<<gradesList[indArray]<<" ";
        }
    }
    
    return 0;
}