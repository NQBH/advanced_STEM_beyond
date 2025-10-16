//nhan 2 ma tran A thuoc Rmxn va B thuoc Rnxp
#include <iostream>
using namespace std;
int main() {
    const int MAX = 100;
    int m, n, p;
    int a[MAX][MAX], b[MAX][MAX], ketqua[MAX][MAX];
    cout << "nhap hang: ";
    cin >> m;
    cout << "nhap cot: ";
    cin >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
    cout << "nhap cot cua ma tran B: ";
    cin >> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << "b[" << i << "][" << j << "]=";
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            ketqua[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ketqua[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "ma tran A * B la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << ketqua[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}