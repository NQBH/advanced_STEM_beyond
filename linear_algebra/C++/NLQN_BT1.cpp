//nhap vao so hang, so cot va cac phan tu ma tran A thuoc Rmxn, sau do in ra
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
    return 0;
}