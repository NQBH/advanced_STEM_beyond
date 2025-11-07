#include <bits/stdc++.h>
#define int long long
using namespace std;

int C(int n) {
    if (n < 0) return 0;
    return n * (n - 1) / 2;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        s = " " + s;
        int ans = (s[1] - 'a') * 25 + s[2] - 'a' + ((s[2] < s[1]) ? 1 : 0);
        cout << ans << endl;
        // 26 blocks, each block size = 25
    }
}
