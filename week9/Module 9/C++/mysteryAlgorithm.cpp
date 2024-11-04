#include <iostream>
using namespace std;

int main()
{
    int i, n, p, j, curr, temp;
    int seq[7];

    cout<<"Enter length less than or equal to 7: ";
    cin>>n;

    cout<<"Enter sequence: ";
    for (int ind = 0; ind <= n; ind++)
        {
            cin>>curr;
            seq[ind] = curr;
        }

    i = 1;
    j = n;
    p = 3;

    while (i < j)
    {
        while (i < j && seq[i - 1] < p)
        {
            i += 1;
        }
        while (i < j && seq[j - 1] >= p)
        {
            j -= 1;
        }
        if (i < j)
        {
            temp = seq[i - 1];
            seq[i - 1] = seq[j - 1];
            seq[j - 1] = temp;
        }
    }

    for (int ind = 0; ind <= n; ind++)
    {
        cout<<seq[ind]<<" ";
    }

    return 0;
}