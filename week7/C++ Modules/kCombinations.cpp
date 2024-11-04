//k-combination problem 
//program reads n and k from user and prints value of n choose k

#include <iostream>
using namespace std;

int main()
{

    int n, k, nFact, kFact, n_kFact, kCombination;

    cout<<"Enter n and k: ";
    cin>>n>>k;

    nFact = 1;
    kFact = 1;
    n_kFact = 1;

    for (int i = 1; i <= n; i++)
        {
            nFact *= i;
        }

    for (int i = 1; i <= k; i++)
        {
            kFact *= i;
        }

    for (int i = 1; i <= n-k; i++)
        {
            n_kFact *= i;
        }

    kCombination = nFact/(kFact*n_kFact);

    cout<<kCombination;

    return 0;
}