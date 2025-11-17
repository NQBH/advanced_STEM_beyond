#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, A = 0, B = 0, C = 0;
		cin >> n;
		vector<string> a(n), b(n), c(n);
		map<string, int> f;
		for (string &x : a) {
			cin >> x;
			++f[x];
		}
		for (string &x : b) {
			cin >> x;
			++f[x];
		}
		for (string &x : c) {
			cin >> x;
			++f[x];
		}
		for (string x : a)
			if (f[x] == 1) A += 3;
			else if (f[x] == 2) A += 1;
		for (string x : b)
			if (f[x] == 1) B += 3;
			else if (f[x] == 2) B += 1;
		for (string x : c)
			if (f[x] == 1) C += 3;
			else if (f[x] == 2) C += 1;
		cout << A << ' ' << B << ' ' << C << '\n';
	}
}