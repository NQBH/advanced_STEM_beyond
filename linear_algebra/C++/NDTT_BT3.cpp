#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "so hang: ";
    cin >> n;
    cout << "so cot: ";
    cin >> m;

    double a[100][100], b[100][100];

    cout << "nhap phan tu trong ma tran:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int x;
    cout << "nhap 1 so de nhan voi ma tran:\n";
    cin >> x;
    cout << "ket qua sau khi nhan:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = a[i][j] * x;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
