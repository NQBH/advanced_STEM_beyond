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
		vector<int> w(n), h(n);
		for (int i = 0; i < n; ++i) cin >> w[i] >> h[i];
		cout << 2 * (*max_element(w.begin(), w.end()) + *max_element(h.begin(), h.end())) << '\n';
	}
}