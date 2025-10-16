#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, p;

    cout << "Nhap so hang cua ma tran A: ";
    cin >> m;
    cout << "Nhap so cot cua ma tran A (dong thoi la so hang cua B): ";
    cin >> n;
    cout << "Nhap so cot cua ma tran B: ";
    cin >> p;

    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(p));
    vector<vector<int>> C(m, vector<int>(p, 0));

    cout << "Nhap cac phan tu cua ma tran A";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "Nhap cac phan tu cua ma tran B";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << "B[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Ma tran ket qua C = A * B la:";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
