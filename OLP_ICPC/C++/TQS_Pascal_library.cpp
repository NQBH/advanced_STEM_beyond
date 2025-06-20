#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    while (n != 0 and d != 0) {
        vector<vector<int>> a(d + 1, vector<int>(n + 1));
        bool kq = false;
        for (int i = 0; i < d; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < d; ++j)
                sum += a[j][i];
            if (sum == d) {
                kq = true;
                break;
            }
        }
        if (kq) cout << "Yes" << "\n";
        else cout << "No" << "\n";
        cin >> n >> d;
    }
}