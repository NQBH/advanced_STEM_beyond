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
		int a_xor = 0;
		for (int &x : a) {
			cin >> x;
			a_xor ^= x;
		}
		if (n & 1) cout << a_xor << '\n';
		else cout << (a_xor == 0 ? "0\n" : "-1\n");
	}
}