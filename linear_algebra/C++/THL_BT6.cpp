#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    vector<vector<int > > A(m, vector<int>(n));
    cout << "Nhap cac phan tu cua ma tran A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    int p;
    cout << "Nhap kich thuoc vector b: ";
    cin >> p;
    vector<int> b(p);
    cout << "Nhap cac phan tu cua vector b:\n";
    for (int i = 0; i < p; ++i)
        cin >> b[i];
    if (m != p) {
        cout << "Impossible";
        return 0;
    }
    vector<vector<int > > Ab(m, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            Ab[i][j] = A[i][j];
        Ab[i][n] = b[i];
    }
    cout << "\nMa tran bo sung [A|b]:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n + 1; ++j)
            cout << Ab[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
