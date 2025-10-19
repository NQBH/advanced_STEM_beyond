#include <bits/stdc++.h>
using std::cin, std::cout, std::cerr, std::endl;

int query(std::vector<int> s) {
    cout << "? " << s.size() << ' ';
    std::sort(s.begin(), s.end());
    for (int u : s) cout << u << ' ';
    cout << '\n';
    int x; cin >> x; return x;
}
void solve() {
    int n; cin >> n; int m = 2 * n;
    std::vector<int> ans(m + 1), s, t;
    for (int i = 1; i <= m; ++i) {
        s.push_back(i);
        int r = query(s);
        if (r > 0)
            ans[i] = r, s.pop_back(), t.push_back(i);
    }
    for (int i = 1; i <= m; ++i) if (ans[i] == 0)
            t.push_back(i), ans[i] = query(t), t.pop_back();
    cout << "! ";
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << " \n"[i == m];
}
int main() { int t; cin >> t; while (t--) solve(); return 0; }