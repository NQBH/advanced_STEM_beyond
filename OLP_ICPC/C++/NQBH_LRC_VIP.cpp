#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		set<int> a;
		int a_max = 0, idx_max = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			a.insert(x);
			if (x > a_max) {
				a_max = x;
				idx_max = i;
			}
		}
		if (a.size() == 1) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < n; ++i)
				if (i != idx_max) cout << "1 ";
				else cout << "2 ";
			cout << '\n';
		}
	}
}