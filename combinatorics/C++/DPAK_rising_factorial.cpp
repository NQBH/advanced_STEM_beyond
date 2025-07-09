#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> x;

vector<int> mul(vector<int> a, int num) {
    // num : (x - num) * a
    int N = a.size() + 1;
    vector<int> temp(N, 0);

    for (int i = 0; i < N - 1; ++i) temp[i + 1] = a[i];
    for (int i = 0; i < a.size(); ++i) temp[i] += (-num) * a[i];
    return temp;
}

int main() {
    cin >> n;
    x.resize(n + 1);
    x[0] = {1};
    x[1] = {0, 1};
    x[2] = {0, 1, 1};
    for (int i = 3; i <= n; ++i)
        // x[i - 1] * (x - (-i + 1))
        x[i] = mul(x[i - 1], -i + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < x[i].size(); j++) {
            if (j == 0) cout << x[i][j];
            else {
                if (x[i][j] > 0) cout << " + ";
                else cout << " - ";
                int val = abs(x[i][j]);
                if (val != 1) cout << val << "x";
                else cout << "x";
                if (j > 1) cout << "^" << j << " ";
            }
        }
        cout << '\n';
    }
}