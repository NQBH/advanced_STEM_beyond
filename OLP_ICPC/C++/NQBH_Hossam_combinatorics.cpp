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
		for (int &x : a) cin >> x;
		int M = *max_element(a.begin(), a.end()), m = *min_element(a.begin(), a.end()), fM = 0, fm = 0;
		if (M == m) cout << 1LL * n * (n - 1) << '\n';
		else {
			for (int x : a)
				if (x == M) ++fM;
				else if (x == m) ++fm;
			cout << 2LL * fm * fM << '\n';
		}
	}
}