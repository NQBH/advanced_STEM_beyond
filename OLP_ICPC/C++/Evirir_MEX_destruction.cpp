#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (!a.empty() && a.back() == 0) a.pop_back();
	reverse(a.begin(), a.end());
	while (!a.empty() && a.back() == 0) a.pop_back();
	reverse(a.begin(), a.end());
	if (a.empty()) {
		cout << 0 << '\n';
        return;
	}
	bool hasZero = false;
	for (const auto x : a) hasZero |= x == 0;
	if (hasZero) cout << 2 << '\n';
	else cout << 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}