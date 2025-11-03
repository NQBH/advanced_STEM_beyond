#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(4, 0);
        for (int i = 0; i < n; i++) {
            a[i % 4]++;
        }
        if (a[1] == a[2] && a[0] == a[3]) {
            cout << "Bob";
        }
        else {
            cout << "Alice";
        }
        cout << endl;
    }
}