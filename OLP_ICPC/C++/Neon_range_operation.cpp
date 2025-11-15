#include <bits/stdc++.h>
using namespace std;
using li = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		li s = 0, mn = 0, bst = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			s += x;
			li cur = (i + 1) * li(i + 2) - s;
			mn = min(mn, cur);
			bst = max(bst, cur - mn);
		}
		cout << s + bst << '\n';
	}
}