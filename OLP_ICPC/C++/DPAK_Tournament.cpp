#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (k > 1) {
            cout << "yEs" << endl;
            continue;
        }
        int cur = a[j];
        sort(a.begin() + 1, a.end());
        int MAX = a[n];
        if (MAX == cur) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}