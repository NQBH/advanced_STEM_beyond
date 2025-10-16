#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "nhap so hang: " << endl;
    cin >> m;
    cout << "nhap so cot: " << endl;
    cin >> n;

    double A[m][n];
    cout << "nhap so phan tu cua ma tran A: ";
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    int a;
    cout << "Nhap so phan tu cua Vector B: " << endl;
    cin >> a;
    double B[a];
    for (int i  = 0 ; i < a ; i++)
    {
        cout << "B[" << i << "] = ";
        cin >> B[i];
    }

    cout << "Ma tran A: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "\n";
        cout << endl;
    }

    cout << "vector B: " << endl;
    for (int i = 0 ; i < a ; i++)
    {
        cout << B[i] << endl;
    }

    // Kiểm tra
    if (a == m)
    {
        cout << "ma tran bo sung" << endl;
        for (int i = 0 ; i < m ; i++)
        {
            for (int j = 0 ; j < n ; j++)
                cout << A[i][j] << "\t";
            cout << B[i] << endl;
        }
    }
    else {
        cout << "\n Impossible!! \n";
    }
    return 0;
}