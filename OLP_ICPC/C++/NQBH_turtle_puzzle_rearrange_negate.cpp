#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			ans += abs(x);
		}
		cout << ans << '\n';
	}
}