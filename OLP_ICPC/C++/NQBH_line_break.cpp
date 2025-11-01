#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; ++i) cin >> s[i];
        int S = 0;
        bool done = false;
        for (int i = 0; i < n; ++i) {
            S += s[i].size();
            if (S > m) {
                done = true;
                cout << i << '\n';
                break;
            }
        }
        if (!done) cout << n << '\n';
    }
}