#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhập số dòng và cột của ma trận A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhập ma trận A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    int b_size;
    cout << "Nhập kích thước vector b: ";
    cin >> b_size;

    vector<double> b(b_size);
    cout << "Nhập vector b:\n";
    for (int i = 0; i < b_size; i++)
        cin >> b[i];

    if (b_size != m) {
        cout << "Impossible\n";
        return 0;
    }

    cout << "Ma trận bổ sung [A|b]:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << "| " << b[i] << "\n";
    }

    return 0;
}