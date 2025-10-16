#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va cot cua ma tran A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    int mb;
    cout << "Nhap so phan tu cua vector b: ";
    cin >> mb;

    vector<double> b(mb);
    cout << "Nhap cac phan tu cua vector b:\n";
    for (int i = 0; i < mb; ++i)
        cin >> b[i];

    if (mb != m) {
        cout << "Impossible\n";
        return 0;
    }

    cout << "Ma tran bo sung [A|b]:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << "\t";
        cout << b[i] << endl;
    }

    return 0;
}