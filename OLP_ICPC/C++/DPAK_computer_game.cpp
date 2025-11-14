#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s[3];
        cin >> s[1] >> s[2];
        s[1] = " " + s[1];
        s[2] = " " + s[2];
        bool check = false;
        for (int i = 1; i <= n; i++) {
            if (s[1][i] == '1' && s[1][i] == s[2][i]) {
                check = true;
                break;
            }
        }
        cout << (!check ? "YES" : "NO") << endl;
    }
    return 0;
}