#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		long long w, l, n;
		int tmp = 1;
		cin >> w >> l >> n;
		while (w % 2 == 0) {
			w /= 2;
			tmp *= 2;
		}
		while (l % 2 == 0) {
			l /= 2;
			tmp *= 2;
		}
		if (tmp >= n) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
