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
    int m1, n1, m2, n2;

    cout << "=<3= cong va tru ma tran =<3=" << endl;

    vector<vector<double>> A = nhap_ma_tran(m1, n1, "A");

    cout << "\n";
    vector<vector<double>> B = nhap_ma_tran(m2, n2, "B");

    if (m1 != m2 || n1 != n2 || A.empty() || B.empty()) {
        cerr << "\nLoi: Hai ma tran phai cung kich thuoc de cong hoac tru!" << endl;
        return 1;
    }

    int m = m1;
    int n = n1;
    vector<vector<double>> C_cong(m, vector<double>(n));
    vector<vector<double>> C_tru(m, vector<double>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C_cong[i][j] = A[i][j] + B[i][j];
            C_tru[i][j] = A[i][j] - B[i][j];
        }
    }

    xuat_ma_tran(C_cong, "A + B");
    xuat_ma_tran(C_tru, "A - B");

    return 0;
}