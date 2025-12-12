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
		cin >> n;
		vector<int> odd, even;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (a & 1) odd.push_back(a);
			else even.push_back(a);			
		}
		sort(odd.rbegin(), odd.rend());
		sort(even.rbegin(), even.rend());
		int n_odd = odd.size(), n_even = even.size();
		vector<ll> peven(n_even + 1, 0);
		for (int i = 0; i < n_even; ++i) peven[i + 1] = peven[i] + even[i];
		for (int k = 1; k <= n; ++k) {
			if (!n_odd) {
				cout << "0 ";
				continue;
			}
			ll curr_score = odd[0];
			int max_even_coin = min(n_even, k - 1);
			if ((k - 1 - max_even_coin) & 1) --max_even_coin;
			if (max_even_coin >= 0 && k - max_even_coin <= n_odd) {
				curr_score += peven[max_even_coin];
				cout << curr_score << ' ';
			} else cout << "0 ";
		}
		cout << '\n';
	}
}