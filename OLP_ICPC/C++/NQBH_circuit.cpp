#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, n1 = 0;
		cin >> n;
		n <<= 1;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (x) ++n1;
		}
		int n0 = n - n1;
		cout << (n1 & 1 ? 1 : 0) << ' ';
		if (n0 == 0 || n1 == 0) cout << "0\n";
		else cout << min(n0, n1) << '\n';		
	}
}