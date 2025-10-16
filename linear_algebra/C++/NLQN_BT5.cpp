//tim ma tran chuyen vi AT thuoc Rnxm cua ma tran A thuoc Rmxn
#include<iostream>
using namespace std;
int main() {
    int m, n;
    cout << "nhap hang: ";
    cin >> m;
    cout << "nhap cot: ";
    cin >> n;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
    cout << "ma tran vua nhap la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int at[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            at[i][j] = a[j][i];
        }
    }
    cout << "ma tran chuyen vi la: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << at[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}