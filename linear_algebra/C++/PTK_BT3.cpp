#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m = "; cin >> m;
    cout << "Nhap so cot n = "; cin >> n;

    int A[100][100];
    cout << "Nhap ma tran A:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    double c;
    cout << "Nhap so thuc c = "; cin >> c;

    cout << "Ma tran sau khi nhan " << c << " la:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] * c << " ";
        }
        cout << endl;
    }

    return 0;
}