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
		set<int> S;
		for (int &x : a) {
			cin >> x;
			++f[x];
			S.insert(x);
		}
		if (n == 1) cout << a[0] << '\n';
		else {
			for (auto i : S) cout << i << ' ';
			for (auto e : f)
				if (e.second > 1)
					for (int i = 0; i < e.second - 1; ++i) cout << e.first << ' ';
			cout << '\n';
		}		
	}
}