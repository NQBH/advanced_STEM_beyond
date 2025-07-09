#include <bits/stdc++.h>
using namespace std;

void stir1(int n, vector<vector<long long>>& s) {
    s.assign(n + 1, vector<long long>(n + 1, 0));
    s[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            s[i][j] = s[i - 1][j - 1] - (i - 1) * s[i - 1][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    if (k == 0) {
        cout << 1;
        return 0;
    }

    vector<vector<long long>> s;
    stir1(k, s);

    cout << "(x)_" << k << " = ";
    for (int j = 0; j <= k; ++j) {
        long long coef = s[k][j];
        if (coef == 0) continue;
        if (coef > 0 && j > 1) cout << "+";
        if (coef == -1) cout << "-";
        else if (!(coef == 1)) cout << coef;

        if (j == 1) {
            cout << "x";
        } else {
            cout << "x^" << j;
        }
    }
    return 0;
}