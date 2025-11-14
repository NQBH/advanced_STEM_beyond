#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        vector<char> a;
        for (int i = 1; i <= n; i++) {
            if (a.empty()) a.push_back(s[i]);
            else {
                if (s[i] != a.back()) {
                    a.push_back(s[i]);
                }
            }
        }
        int ans = 0;
        for (auto i : a) ans += (i == '0');
        cout << min(2LL,ans) << endl;
    }
    return 0;
}