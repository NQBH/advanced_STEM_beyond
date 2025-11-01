#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		set<int> A, B;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			A.insert(x);
		}
		for (int i = 0; i < n; ++i) {
			cin >> x;
			B.insert(x);
		}
		if (A.size() + B.size() > 3) cout << "YES\n";
		else cout << "NO\n";
	}
}