//cộng trừ 2 ma trận A,B thuộc Rmxn
#include<iostream>
using namespace std;
int main(){
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
    int b[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "b[" << i << "][" << j << "]=";
            cin >> b[i][j];
        }
    }
    int cong[m][n], tru[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cong[i][j] = a[i][j] + b[i][j];
            tru[i][j] = a[i][j] - b[i][j];
        }
    }
    cout << "ma tran A + B la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << cong[i][j] << " ";
        }
        cout << endl;
    }
        cout << "ma tran A - B la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << tru[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}