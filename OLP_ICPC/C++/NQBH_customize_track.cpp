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
		long long S = 0;
		for (int &x : a) {
			cin >> x;
			S += x;
		}
		int r = S % n;
		cout << 1LL * r * (n - r) << '\n';
	}
}