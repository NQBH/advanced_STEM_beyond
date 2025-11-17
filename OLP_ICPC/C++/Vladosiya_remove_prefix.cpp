#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); ++i)

int main() {
	int t;
	cin >> t;
	forn(tt, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n) cin >> a[i];
		bool yes = false;
		set<int> c;
		for (int i = n - 1; i >= 0; --i) {
			if (c.count(a[i])) {
				cout << i + 1 << endl;
				yes = true;
				break;
			}
			c.insert(a[i]);
		}
		if (!yes) cout << 0 << endl;
	}
}