#include <bits/stdc++.h>
using namespace std;
int main() {
    int num_row, num_col;
    int m, n;
    cout << "Nhap ma tran A:\n";
    cin >> num_row >> num_col;
    vector<vector<int> > a(num_row, vector<int>(num_col));
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++)
            cin >> a[i][j];
    cout << "Nhap ma tran B:\n";
    cin >> m >> n;
    vector<vector<int> > b(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    if (num_col != m) cout << "Khong the nhan hai ma tran";
    else {
        cout << "Nhan 2 ma tran:\n";
        for (int i = 0; i < num_row; i++) {
            cout << "\n";
            for (int j = 0; j < n; j++) {
                int ans = 0;
                for (int k = 0; k < num_col; k++)
                    ans += a[i][k] * b[k][j];
                cout << ans << " ";
            }
        }
    }
}
