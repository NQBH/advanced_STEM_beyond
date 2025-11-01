#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, a;
    cin >> x >> y >> a;
    if (a % (x + y) < x) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}