//phep nhan vo huong ma tran A thuoc Rmxn voi 1 so thuc c thuoc R
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
    float c;
    int ketqua[m][n];
    cout << "nhap so thuc c: ";
    cin >> c;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ketqua[i][j] = a[i][j] * c;
        }
    }
    cout << "ma tran nhan voi so thuc c: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ketqua[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}