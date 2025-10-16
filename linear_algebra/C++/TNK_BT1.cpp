#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int m, n; 

    cout << "=<3=nhap va xuat ma tran =<3=" << endl;
    
    cout << "Nhap so hang (m): ";
    cin >> m;
    cout << "Nhap so cot (n): ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cerr << "Kich thuoc ma tran ko hop le!" << endl;
        return 1;
    }

    vector<vector<double>> A(m, vector<double>(n));

    cout << "Nhap cac phan tu cua ma tran (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\n=<3= ma tran vua nhap la =<3=" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << fixed << setprecision(2) << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}