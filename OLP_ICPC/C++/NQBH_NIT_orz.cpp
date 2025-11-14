#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll z;
		cin >> n >> z;
		vector<ll> a(n);
		for (ll &x : a) cin >> x;
		cout << (*max_element(a.begin(), a.end()) | z) << '\n';
	}
}