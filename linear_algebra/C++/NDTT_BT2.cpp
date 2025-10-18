#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "so hang: ";
    cin >> n;
    cout << "so cot: ";
    cin >> m;

    double a[100][100], b[100][100], c[100][100];

    cout << "nhap phan tu trong ma tran a:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << "nhap phan tu trong ma tran b:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    cout << "ma tran A - ma tran B\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = a[i][j] - b[i][j];
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
