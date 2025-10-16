#include <iostream>
using namespace std;
const int MAX = 100;
int main() {
    int m, n;
    double A[MAX][MAX];
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Ma tran A:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}

//bài 2 cộng trừ 2 ma trận
#include <iostream>
using namespace std;

const int MAX = 100;
int main() {
    int m, n;
    double A[MAX][MAX], B[MAX][MAX], C_Sum[MAX][MAX], D_Diff[MAX][MAX];
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i+1 << "][" << j+1 << "] = ";
            cin >> A[i][j];
    }
    cout << "Nhap cac phan tu cua ma tran B:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "B[" << i+1 << "][" << j+1 << "] = ";
            cin >> B[i][j];
    }
    // Tính tổng và hiệu
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            C_Sum[i][j] = A[i][j] + B[i][j];
            D_Diff[i][j] = A[i][j] - B[i][j];
    }
    cout << "\nMa tran A:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << "\nMa tran B:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << B[i][j] << " ";
        cout << endl;
    }
    cout << "\nTong C = A + B:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << C_Sum[i][j] << " ";
        cout << endl;
    }
    cout << "\nHieu D = A - B:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << D_Diff[i][j] << " ";
        cout << endl;
    }
    return 0;
}
