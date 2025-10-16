#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    double c;
    cout << "Nhap so dong va so cot ";
    cin >> m>> n;
    vector<vector<double>> A(m, vector<double>(n));
    cout << "nhap cac phan tu cua ma tran A:";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
         cin >> A[i][j];
    cout << "Nhap so thuc c: ";
    cin >> c;
    vector<vector<double>> B(m, vector<double>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = c * A[i][j];
    cout << "Ma tran sau khi nhan voi " << c << " la:";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << B[i][j] << " ";
    }
    return 0;
}