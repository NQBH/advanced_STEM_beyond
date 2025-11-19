#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		if (a != b) {
			char c = a[0];
			a[0] = b[0];
			b[0] = c;
		}
		cout << a << ' ' << b << '\n';
	}
}