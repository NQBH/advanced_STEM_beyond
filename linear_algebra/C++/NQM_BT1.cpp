#include <iostream>
using namespace std;

const int MAX = 100;

void nhap(double A[] [MAX], int &m, int &n){
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        cout << "Nhap hang " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
         
    }
    
}

void xuat(double A[][MAX], int m, int n) {
    cout << "Ma tran da nhap: " << endl;
    for ( int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "[ " << A[i][j] << " ] " << " ";
        }

        cout << endl;
        
    }
    
}

int main() {
    double A[MAX][MAX];
    int m, n;
    
    nhap(A, m, n);
    xuat(A, m, n);
    return 0;
}
