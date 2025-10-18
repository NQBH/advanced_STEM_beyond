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

vector<vector<float> > nhanVoHuong(const vector<vector<float> > &A, int n, int m, float k) {
    vector<vector<float> > B(n, vector<float>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            B[i][j] = A[i][j] * k;
    return B;
}

int main() {
    vector<vector<float> > A, B;
    int n, m;
    float k;

    nhapMT(A, n, m);

    cout << "\nNhap he so vo huong k = ";
    cin >> k;

    B = nhanVoHuong(A, n, m, k);
    xuatMT(A, n, m);

    cout << "\nMa tran sau khi nhan voi " << k << " la:\n";
    xuatMT(B, n, m);

    return 0;
}