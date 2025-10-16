#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang (m): ";
    cin >> m;
    cout << "Nhap so cot (n): ";
    cin >> n;

    vector<vector<double>> A(m, vector<double>(n));

    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "Ma tran da nhap:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << fixed << setprecision(2) << A[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}