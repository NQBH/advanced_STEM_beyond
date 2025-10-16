#include <bits/stdc++.h>
using namespace std;
int main() {
    int num_row, num_col;
    cout << "Nhap ma tran 1:\n";
    cin >> num_row >> num_col;
    vector<vector<int> > a(num_row, vector<int>(num_col));
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++)
            cin >> a[i][j];
    cout << "Nhap ma tran 2:\n";
    vector<vector<int> > b(num_row, vector<int>(num_col));
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++)
            cin >> b[i][j];
    cout << "Tong 2 ma tran:\n";
    for (int i = 0; i < num_row; i++) {
        cout << "\n";
        for (int j = 0; j < num_col; j++)
            cout << a[i][j] + b[i][j] << " ";
    }
    cout << "Hiệu 2 ma tran:\n";
    for (int i = 0; i < num_row; i++) {
        cout << "\n";
        for (int j = 0; j < num_col; j++)
            cout << a[i][j] - b[i][j] << " ";
    }
}
