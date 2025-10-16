#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang (m) va so cot (n) cua A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap " << m << " hang cua ma tran A:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    int p;
    cout << "Nhap so phan tu cua vector b: ";
    cin >> p;

    vector<double> b(p);
    cout << "Nhap " << p << " phan tu cua vector b:\n";
    for (int i = 0; i < p; ++i) {
        cin >> b[i];
    }

    if (m != p) {
        cout << "\nKhong the ghep\n";
    } else {
        cout << "\nMa tran bo sung [A|b]:\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << A[i][j] << " ";
            }
            cout << "| " << b[i] << "\n";
        }
    }

    return 0;
}