#include <iostream>
#include <vector>
using namespace std;

void nhapMaTran(vector<vector<double>>& A, int& m, int& n) {
    cout << "Nhap so hang: "; cin >> m;
    cout << "Nhap so cot: "; cin >> n;
    A.resize(m, vector<double>(n));
    cout << "Nhap cac phan tu ma tran:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
}

void xuatMaTran(const vector<vector<double>>& A) {
    for (auto& dong : A) {
        for (auto x : dong)
            cout << x << " ";
        cout << endl;
    }
}

void hoanDoiDong(vector<vector<double>>& A, int i, int j) {
    swap(A[i], A[j]);
}

void nhanDongVoiHangSo(vector<vector<double>>& A, int i, double c) {
    for (int k = 0; k < A[i].size(); k++)
        A[i][k] *= c;
}

void congBoiSoVaoDong(vector<vector<double>>& A, int i, int j, double c) {
    for (int k = 0; k < A[i].size(); k++)
        A[i][k] += c * A[j][k];
}

int main() {
    vector<vector<double>> A;
    int m, n, chon;
    nhapMaTran(A, m, n);

    do {
        cout << "\nMa tran hien tai:\n";
        xuatMaTran(A);
        cout << "\n1. Hoan doi hai dong\n2. Nhan dong voi hang so\n3. Cong boi so dong\n4. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        if (chon == 1) {
            int i, j;
            cout << "Nhap i, j: "; cin >> i >> j;
            hoanDoiDong(A, i - 1, j - 1);
        } 
        else if (chon == 2) {
            int i; double c;
            cout << "Nhap i va c: "; cin >> i >> c;
            nhanDongVoiHangSo(A, i - 1, c);
        } 
        else if (chon == 3) {
            int i, j; double c;
            cout << "Nhap i, j, c: "; cin >> i >> j >> c;
            congBoiSoVaoDong(A, i - 1, j - 1, c);
        }

    } while (chon != 4);

    cout << "\nMa tran cuoi cung:\n";
    xuatMaTran(A);
    return 0;
}
