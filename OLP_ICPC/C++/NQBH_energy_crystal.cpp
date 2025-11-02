#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, ans = 0;
		cin >> x;
		vector<int> a(3, 0); // will be sorted
		while (a[0] < x) { // greedy: increase smallest crystal
			a[0] = 2 * a[1] + 1;
			sort(a.begin(), a.end());
			++ans;
		} 
		cout << ans << '\n';
	}
}