#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k = 0;
		cin >> n;
		vector<int> h(n);
		map<int, int> f;
		for (int &x : h) {
			cin >> x;
			++f[x];
		}
		for (auto e : f) k = max(k, e.second);
		cout << n - k << '\n';
	}
}