#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll t, a, b, k, val;
	cin >> t;
	while (t--) {
		cin >> a >> b >> k;
		if (a == 1 || b == 1 || k == 1) {
			for (ll i = 0; i < k; ++i) cin >> val;
			for (ll i = 0; i < k; ++i) cin >> val;
			cout << 0 << '\n';
			continue;
		}
		else {
			long long ans = k * (k - 1) / 2;			
			set<ll> A, B;
			vector<ll> freq_A(a + 1, 0), freq_B(b + 1, 0);
			for (ll i = 0; i < k; ++i) {
				cin >> val;
				++freq_A[val];
				A.insert(val);
			}
			for (ll i = 0; i < k; ++i) {
				cin >> val;
				++freq_B[val];
				B.insert(val);
			}
			if (A.size() == 1 || B.size() == 1) cout << 0 << '\n';
			else {
				for (ll i = 1; i <= a; ++i)
					if (freq_A[i] >= 2) ans -= freq_A[i] * (freq_A[i] - 1) / 2;
				for (ll i = 1; i <= b; ++i)
					if (freq_B[i] >= 2) ans -= freq_B[i] * (freq_B[i] - 1) / 2;
				cout << ans << '\n';
			}
		}
	}
}