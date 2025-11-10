#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> f;
		for (int &x : a) {
			cin >> x;
			++f[x];
		}
		if (n == 1) cout << "0\n";
		else {
			auto f_max = max_element(f.begin(), f.end(),
			[](const auto & p1, const auto & p2) {
				return p1.second < p2.second;
			});
			cout << n - f_max->second << '\n';
		}
	}
}