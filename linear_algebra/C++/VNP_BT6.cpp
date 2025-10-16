#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang cua ma tran A: ";
    cin >> m;
    cout << "Nhap so cot cua ma tran A: ";
    cin >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A:";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int mb;
    cout << "Nhap so phan tu cua vector b: ";
    cin >> mb;

    vector<double> b(mb);
    cout << "Nhap cac phan tu cua vector b:\n";
    for (int i = 0; i < mb; i++) {
        cout << "nhap";
        cin >> b[i];
    }

    if (mb != m) {
        cout << "Impossible";
        return 0;
    }

    cout << "Ma tran bo sung [A|b]:";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "| " << b[i] << endl;
    }

    return 0;
}