#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		set<int> x;
		map<int, int> f;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			x.insert(a);
			++f[a];
		}
		for (auto e : f) {
			if (e.second > 1) {
				if (!x.count(e.first + 1)) {
					x.insert(e.first + 1);
					--f[e.first];
					++f[e.first + 1];
				}
			} else {
				if 
			}
		}
		/*
		sort(x.begin(), x.end());
		for (int i = 0; i < n - 1; ++i)
			if (x[i] == x[i + 1]) {
				if (x[i] + 1 != x[i + 1]) {
					++ans;
					++x[i];
				}
			} else if (x[i] < x[i + 1]) ++ans;
		
		*/
		cout << x.size() << '\n';
	}
}