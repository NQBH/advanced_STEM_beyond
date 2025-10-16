#include <bits/stdc++.h>
using namespace std;
int main() {
    // m = num_row, n = num_col
    cout << "\nBien doi 1:\n";
    int num_row, num_col;
    cin >> num_row >> num_col;
    vector<vector<int> > a(num_row, vector<int>(num_col));
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++)
            cin >> a[i][j];
    //BDSCD1
    int r1, r2;
    cin >> r1 >> r2;
    for (int i = 0; i < num_col; i++)
        swap(a[r1][i], a[r2][i]);
    for (int i = 0; i < num_row; ++i) {
        cout << '\n';
        for (int j = 0; j < num_col; ++j) cout << a[i][j] << " ";
    }
    //BDSCD2
    cout << "\nBien doi 2:\n";
    int num_row2, num_col2;
    cin >> num_row2 >> num_col2;
    vector<vector<int> > a2(num_row2, vector<int>(num_col2));
    for (int i = 0; i < num_row2; i++)
        for (int j = 0; j < num_col2; j++)
            cin >> a2[i][j];
    int r;
    cin >> r;
    double alpha;
    cin >> alpha;
    for (int i = 0; i < num_col2; ++i)
        a2[r][i] = a[r][i] * alpha;
    for (int i = 0; i < num_row2; ++i) {
        cout << '\n';
        for (int j = 0; j < num_col2; ++j) cout << a2[i][j] << " ";
    }
    //BDSCD3
    int num_row3, num_col3;
    cin >> num_row3 >> num_col3;
    vector<vector<int> > a3(num_row3, vector<int>(num_col3));
    for (int i = 0; i < num_row3; i++)
        for (int j = 0; j < num_col3; j++)
            cin >> a[i][j];
    cout << "\nBien doi 3:\n";
    int k, s; double c;
    cin >> k >> s >> c;
    for (int i = 0; i < num_col3; i++)
        a3[k][i] = a3[k][i] + c * a3[s][i];
    for (int i = 0; i < num_row3; ++i) {
        cout << '\n';
        for (int j = 0; j < num_col3; ++j) cout << a3[i][j] << " ";
    }
}
