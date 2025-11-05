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
		for (int &x : a) cin >> x;
		if (n == 1) {
			cout << "0\n";
			continue;			
		}
		sort(a.begin(), a.end());
		cout << (n - 1) * (a[n - 1] - a[0]) << '\n';
	}
}