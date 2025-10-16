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
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<double> b(m);
    cout << "Nhap cac phan tu cua vector b:\n";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << "\nMa tran bo sung [A|b]:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << "| " << b[i] << endl;
    }

    return 0;
}
