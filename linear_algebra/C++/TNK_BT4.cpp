#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

vector<vector<double>> nhap_ma_tran(int& m, int& n, const string& ten) {
    cout << "Nhap ma tran " << ten << ":" << endl;
    cout << "So hang (m): "; cin >> m;
    cout << "So cot (n): "; cin >> n;

    if (m <= 0 || n <= 0) return {};
    vector<vector<double>> mat(m, vector<double>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ten << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat[i][j];
        }
    }
    return mat;
}

void xuat_ma_tran(const vector<vector<double>>& A, const string& ten) {
    if (A.empty()) return;
    cout << "\n--- Ket qua " << ten << " (" << A.size() << "x" << A[0].size() << ") ---" << endl;
    for (const auto& row : A) {
        for (double val : row) {
            cout << setw(8) << fixed << setprecision(2) << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int m1, n1, m2, n2;

    cout << "=<3= nhan 2 ma tran =<3=" << endl;

    vector<vector<double>> A = nhap_ma_tran(m1, n1, "A");

    cout << "\n";
    vector<vector<double>> B = nhap_ma_tran(m2, n2, "B");

    if (n1 != m2 || A.empty() || B.empty()) {
        cerr << "\nLoi: So cot cua A (" << n1 << ") khong bang so hang cua B (" << m2 << "). Khong the nhan." << endl;
        return 1;
    }

    int m = m1;
    int n = n1;
    int p = n2;

    vector<vector<double>> C(m, vector<double>(p, 0.0));

    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < p; ++k) {
            for (int j = 0; j < n; ++j) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }

    xuat_ma_tran(C, "A x B");

    return 0;
}