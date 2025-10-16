#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	ll t;
	cin >> t;
	while (t--) {
		ll n, a, ans = 0;
		cin >> n;
		vector<ll> odd;
		for (ll i = 0; i < n; ++i) {
			cin >> a;
			if (a & 1) odd.push_back(a);
			else ans += a;
		}
		if (odd.empty()) cout << 0 << '\n';
		else {
			if (odd.size() == 1) {
				ans += odd[0];
				cout << ans << '\n';
			} else { // >= 2 odd fields
				sort(odd.begin(), odd.end());
				for (int i = odd.size() - 1; i >= odd.size() / 2; --i) ans += odd[i];
				cout << ans << '\n';				
			}
		}
	}
}