#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin >> n;
    vecin(g, n);
    ll ans = 0;
    sort(all(g));
    for (int i = n - 1; i >= 0; i -= 2)
        ans += g[i];
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}