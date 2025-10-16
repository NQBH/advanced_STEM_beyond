#include <iostream>
using namespace std;

const int MAX = 100;

void nhap(double A[][MAX], int &m, int &n, string ten = " ") {
    if (ten != " ")
    {
        cout << "Nhap ma tran: " << ten << endl;
    }
    if (m == 0 && n == 0)
    {
        cout << "Nhap so hang: ";
        cin >> m;
        cout << "Nhap so cot: ";
        cin >> n;
    }
    for (int i = 0; i < m; i++)
    {
        cout << "Nhap hang " << i + 1 << " : ";
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }

    }



}

void xuat(double A[][MAX], int m, int n) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "[ " << A[i][j] << " ] " << " ";
        }
        cout << endl;
    }
}

void cong(double A[][MAX], double B[][MAX], double C[][MAX], int m, int n) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }

    }

}

void tru(double A[][MAX], double B[][MAX], double C[][MAX], int m, int n) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }

    }

}

int main() {
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int m = 0, n = 0;
    nhap(A, m, n, "A");
    nhap(B, m, n, "B");

    cout << "Ma tran A: " << endl;
    xuat(A, m, n);
    cout << "Ma tran B: " << endl;
    xuat(B, m, n);

    cout << "A + B = " << endl;
    cong(A, B, C, m, n);
    xuat(C, m, n);

    cout << "A - B = " << endl;
    tru(A, B, C, m, n);
    xuat(C, m, n);
    return 0;
}
