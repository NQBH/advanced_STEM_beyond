#include <iostream>
#include <vector>
using namespace std;

void nhapMT(vector<vector<float> > &A, int &n, int &m) {
    cout << "Nhap so hang: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;
    A.resize(n, vector<float>(m));
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
}

void xuatMT(const vector<vector<float> > &A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }
}

vector<vector<float> > chuyenVi(const vector<vector<float> > &A) {
    int n = A.size();
    int m = (n > 0) ? A[0].size() : 0;
    vector<vector<float> > AT(m, vector<float>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            AT[j][i] = A[i][j];
    return AT;
}

int main() {
    vector<vector<float> > A, AT;
    int n, m;

    nhapMT(A, n, m);
    cout << " Ma tran A ban dau:\n";
    xuatMT(A, n, m);
    AT = chuyenVi(A);
    cout << "Ma tran chuyen vi A^T:\n";
    xuatMT(AT, m, n);

    return 0;
}
