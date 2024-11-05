#include <iostream>
using namespace std;

double eApprox (int n);
int main()
{
    cout.precision(30);

    for (int n = 1; n <= 15; n++)
    {
        cout<<"n = "<<n<<"\t"<<eApprox(n)<<endl;
    }

    return 0;
}

double eApprox(int n)
{
    double nthFactorial = 1;
    double nthTerm = 1.0;
    double approxSum = 1.0;

    for (int i = 1; i <= n; i++)
    {
        nthFactorial *= i;
        nthTerm = 1.0/nthFactorial;
        approxSum += nthTerm;
    }

    if (n==1)
    {
        return 2;
    }
    else
    {
        return approxSum;
    }
    
}