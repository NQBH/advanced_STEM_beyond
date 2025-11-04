#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
	int n;
	cin >> n;
	vecin(gears, n);
	set<int> seen;
	for (auto gear: gears) {
		if (seen.count(gear)) {
			cout << "YES\n";
			return;
		}
		seen.insert(gear);
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}