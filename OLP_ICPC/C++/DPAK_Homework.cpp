#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >>n;
        string a; cin >> a;
        int m; cin >> m;
        string b,c; cin >> b >> c;
        int idx = 0;
        for (auto ch : c) {
            if (ch == 'V') {
                a = b[idx] + a;
            }
            else {
                a = a + b[idx];
            }
            idx++;
        }
        cout << a << endl;
    }
}