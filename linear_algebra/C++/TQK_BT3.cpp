#include <iostream>
using namespace std;

int main() {
    int m, n;
    float A[100][100], c;

    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "Nhap so thuc c: ";
    cin >> c;

    cout << "Ma tran A * c:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] * c << "\t";
        }
        cout << endl;
    }

    return 0;
}
