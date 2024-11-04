//kCombinations using functions

#include <iostream>
using namespace std;

int factorial(int num);
int kCombinations(int n, int k);

int main()
{

    int n, k, nFact, kFact, n_kFact, nChooseK;

    cout<<"Please enter n and k: ";
    cin>>n>>k;

    nChooseK = kCombinations(n,k);

    cout<<n<<" choose "<<k<<" is "<<nChooseK;

    return 0;
}

int factorial(int num)
{
    int num_factorial, i;
    
    num_factorial = 1;

    for (i = 1; i <= num; i++)
        {
            num_factorial *= i;
        }

    return num_factorial;
}

int kCombinations(int n, int k)
{
    int kCombinationsRes;
    
    kCombinationsRes = factorial(n)/(factorial(k)*factorial(n-k));

    return kCombinationsRes;
}