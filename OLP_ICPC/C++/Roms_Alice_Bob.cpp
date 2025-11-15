#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		int n, a;
		cin >> n >> a;
		vector<int> v(n);
		int l = 0, r = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (a > v[i]) ++l;
			if (a < v[i]) ++r;
		}
		cout << (l > r ? a - 1 : a + 1) << '\n';
	}
}