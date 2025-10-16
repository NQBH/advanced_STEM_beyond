#include <bits/stdc++.h>
using namespace std;
int main() {
    int num_row, num_col;
    cin >> num_row >> num_col;
    vector<vector<int> > a(num_row, vector<int>(num_col));
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++)
            cin >> a[i][j];
    cout << "Ma tran chuyen vi:\n";
    for (int i = 0; i < num_col; i++) {
        cout << "\n";
        for (int j = 0; j < num_row; j++)
            cout << a[j][i] << " ";
    }
}