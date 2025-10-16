#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap n > 0: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "n phai la so nguyen duong!!!";
        return 1;
    }
    double A[100][100];
    double B[100][100];
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            A[i][j] = 0;
            if (i == j)
            {
                B[i][j] = 1;
            }
            else
            {
                B[i][j] = 0;
            }
        }
    }
    cout << "Ma tran 0 (" << n << "x" << n << "): \n";
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            cout <<  A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Ma tran don vi (" << n << "x" << n << "): \n";
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            cout <<  B[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}