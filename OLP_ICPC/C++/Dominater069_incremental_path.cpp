#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        set<int> a;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }
        int cur = 1;
        for (char c : s) {
            cur++;
            if (c == 'B') {
                while (a.count(cur)) cur++;
            }
            a.insert(cur);
            if (c == 'B') {
                while (a.count(cur)) cur++;
            }
        }
        cout << a.size() << '\n';
        for (auto& x : a) cout << x << ' ';
        cout << '\n';
    }
}