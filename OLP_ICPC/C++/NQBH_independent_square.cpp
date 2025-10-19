#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool is_square(ll n) {
	ll sr = sqrt(n);
	return (sr * sr == n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x, ans = 0;
		cin >> n;
		vector<ll> a;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (!is_square(x)) a.push_back(x);
		}
		for (auto& x : a) cout << x << ' ';
		ll prod = 1;
		for (int i = 0; i < a.size(); ++i) {
			prod *= a[i];
			if (!is_square(prod)) ++ans;
			else prod /= a[i];
		}
		cout << ans << '\n';
	}
}