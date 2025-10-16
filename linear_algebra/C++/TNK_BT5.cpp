#include <iostream>
#include <vector>
#include <iomanip>

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
    int m, n;

    cout << "=<3= tim ma tran chuyen vi =<3=" << endl;

    vector<vector<double>> A = nhap_ma_tran(m, n, "A");

    if (A.empty()) return 1;

    vector<vector<double>> AT(n, vector<double>(m));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            AT[j][i] = A[i][j];
        }
    }

    xuat_ma_tran(AT, "A^T");

    return 0;
}