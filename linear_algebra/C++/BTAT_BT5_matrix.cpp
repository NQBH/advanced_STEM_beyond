#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va so cot cua A: ";
    cin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n));
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vector<vector<int>> AT(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            AT[i][j] = A[j][i];

    cout << "Ma tran chuyen vi AT la:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << AT[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
