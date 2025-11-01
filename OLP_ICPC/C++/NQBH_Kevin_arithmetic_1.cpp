#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, num_odd = 0, num_even;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (x & 1) ++num_odd;
		}
		num_even = n - num_odd;
		if (num_even) cout << num_odd + 1 << '\n';
		else cout << num_odd - 1 << '\n';
	}
}