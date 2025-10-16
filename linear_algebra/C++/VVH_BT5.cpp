#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    vector<vector<int>> a(m, vector<int>(n));

    cout << "Nhap ma tran:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Ma tran chuyen vi la:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }

    return 0;
}
