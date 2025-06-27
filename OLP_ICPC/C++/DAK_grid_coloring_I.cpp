#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<string> result_grid(n, string(m, ' '));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if ((i + j) % 2 == 0) {
                if (grid[i][j] == 'A') result_grid[i][j] = 'B';
                else result_grid[i][j] = 'A';
            }
            else {
                if (grid[i][j] == 'C') result_grid[i][j] = 'D';
                else result_grid[i][j] = 'C';
            }
    for (int i = 0; i < n; ++i) cout << result_grid[i] << '\n';
    return 0;
}
/*
ý tưởng: tại vị trí i+j là số chẵn, xung quanh là số lẻ (và ngược lại):
- chọn A,B tại ô chẵn | C, D tại ô lẻ
- nếu gốc gốc chẵn là A thì ta chọn B, nếu là C hoặc D thì ta chọn A
- tương tự với các ô có tổng i + j lẻ .
IMPOSSIBLE của đề => bịp
*/
