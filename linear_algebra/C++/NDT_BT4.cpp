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

vector<vector<float> > nhanMT(const vector<vector<float> > &A, int n1, int m1,
                              const vector<vector<float> > &B, int n2, int m2) {
    vector<vector<float> > C;
    if (m1 != n2) {
        cout << "Khong the nhan 2 ma tran: so cot cua A khac so hang cua B.\n";
        return C;
    }
    C.resize(n1, vector<float>(m2, 0));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            for (int k = 0; k < m1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    vector<vector<float> > A, B, C;
    int n1, m1, n2, m2;

    cout << "Nhap ma tran A:\n";
    nhapMT(A, n1, m1);

    cout << "Nhap ma tran B:\n";
    nhapMT(B, n2, m2);

    C = nhanMT(A, n1, m1, B, n2, m2);

    if (!C.empty()) {
        cout << "Ma tran C = A * B:\n";
        xuatMT(C, n1, m2);
    }

    return 0;
}
