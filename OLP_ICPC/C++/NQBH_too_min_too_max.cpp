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
		sort(a.begin(), a.end());
		cout << a[n - 1] - a[0] + a[n - 1] - a[1] + a[n - 2] - a[0] + a[n - 2] - a[1] << '\n';
	}
}