//Print a pine-tree consisting of triangles of increasing sizes

#include <iostream>
using namespace std;

void printPineTree(int n, char symbol);
void printShiftedTriangle(int n, int m, char symbol);

int main()
{
    int num;
    char symbol;

    cout<<"Please enter a positive integer followed by a character: ";
    cin>>num>>symbol;

    printPineTree(num, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m , char symbol)
{
    int numberOfSpaces = m + (n-1);
    int numberOfSymbols = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= numberOfSpaces; j++)
        {
            cout<<" ";
        }
        for (int j = 1; j <= numberOfSymbols; j++)
        {
            cout<<symbol;
        }
        cout<<endl;
        numberOfSpaces -= 1;
        numberOfSymbols += 2;
    }    
}

void printPineTree(int n, char symbol)
{
    int numberOfLines = 2;
    int m = n-1;
    
    for (int i = 1; i <= n; i++)
    {
        printShiftedTriangle(numberOfLines, m , symbol);
        numberOfLines += 1;
        m -= 1;
    }

}