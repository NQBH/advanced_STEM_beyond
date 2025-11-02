#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0, sum = 0;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (x % 3 == 1) ++cnt;
			sum += x % 3;
		}
		if (sum % 3 == 0) cout << "0\n";
		else if (sum % 3 == 1) {
			if (cnt) cout << "1\n";
			else cout << "2\n";
		} else {
			cout << "1\n";
		}
	}
}