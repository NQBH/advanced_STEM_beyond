#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    double c;
    cout << "Nhap so hang m, so cot n: ";
    cin >> m >> n;
    cout << "Nhap he so c: ";
    cin >> c;
    vector<vector<double> > A(m, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    cout << "\nMa tran sau khi nhan voi c = " << c << ":\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] * c << "\t";
        cout << endl;
    }
    return 0;
}
