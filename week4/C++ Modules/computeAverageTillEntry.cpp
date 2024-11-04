#include <iostream>
using namespace std;

int main()
{
    int numOfStudents, curr, sum;
    double average;
    bool seenEndOfInput;

    cout<<"Enter the students' grades (seperated by a space): "<<endl;

    seenEndOfInput = false;
    sum = 0;
    numOfStudents = 0;

    while (seenEndOfInput == false)
    {
        cin>>curr;
        if (curr == -1)
        {
            seenEndOfInput = true;
        }
        else
        {
            numOfStudents ++;
            sum += curr;
        }
    }
    
    average = (double)(sum)/(double)(numOfStudents);

    cout<<"The average is "<<average<<endl;
    
    return 0;
}
