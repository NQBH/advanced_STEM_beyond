#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // m = num_row, n = num_col
    int num_row, num_col;
    cin >> num_row >> num_col;
    vector<vector<int> > a(num_row, vector<int>(num_col));
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++)
            cin >> a[i][j];
    int p; cin >> p;
    vector<int> b(p);
    for (int i = 0; i < p; i++) cin >> b[i];
    if (num_row != p) cout << "impossible";
    else {
        vector<vector<int> > ab(num_row, vector<int>(num_col + 1));
        for (int i = 0; i < num_row; i++) {
            for (int j = 0; j <= num_col; j++)
                ab[i][j] = a[i][j];
            ab[i][num_col] = b[i];
        }
        for (int i = 0; i < num_row; i++) {
            cout << "\n";
            for (int j = 0; j <= num_col; j++)
                cout << ab[i][j] << " ";
        }
    }
}
