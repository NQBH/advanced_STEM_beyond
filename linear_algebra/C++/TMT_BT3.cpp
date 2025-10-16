#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    double c;
    cout << "Nhap hang so c: ";
    cin >> c;

    cout << "\nMa tran sau khi nhan voi " << c << " la:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] * c << " ";
        }
        cout << "\n";
    }

    return 0;
}
