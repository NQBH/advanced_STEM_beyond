#include<iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m ;
    cout << "Nhap so cot: ";
    cin >> n;
    double A[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            cout << "Nhap phan tu A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    if (m != n)
    {
        cout << "Khong phai ma tran vuong!!!" << endl;
        return 0;
    }

    bool duongcheo = true, tamgiactren = true, tamgiacduoi = true, doixung = true;

    // Kiểm tra các loại ma trận
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && A[i][j] != 0)
                duongcheo = false;

            if (i > j && A[i][j] != 0)
                tamgiactren = false;

            if (i < j && A[i][j] != 0)
                tamgiacduoi = false;

            if (A[i][j] != A[j][i])
                doixung = false;
        }
    }

    if (duongcheo)
        cout << "Ma tran nay la ma tran duong cheo." << endl;
    else if (tamgiactren)
        cout << "Ma tran nay la ma tran tam giac tren." << endl;
    else if (tamgiacduoi)
        cout << "Ma tran nay la ma tran tam giac duoi." << endl;
    else if (doixung)
        cout << "Ma tran nay la ma tran doi xung." << endl;
    else
        cout << "Ma tran nay khong thuoc cac loai tren." << endl;

    return 0;
}