#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    double A[m][n];
    for (int i = 0; i < m; i++)    {
        for (int j = 0; j < n; j++)   {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    cout << "Ma tran vua nhap:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}