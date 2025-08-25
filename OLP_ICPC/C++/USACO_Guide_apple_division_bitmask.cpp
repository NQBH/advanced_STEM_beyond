#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<ll> weights(n);
	for (ll &w : weights) cin >> w;
	ll ans = INT64_MAX;
	for (int mask = 0; mask < (1 << n); ++mask) {
		ll sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) sum1 += weights[i]; // check if the ith bit is toggled
			else sum2 += weights[i];
		}
		ans = min(ans, abs(sum1 - sum2));
	}
	cout << ans << '\n';
}