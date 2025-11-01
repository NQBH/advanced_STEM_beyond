#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());
		int curr_num = 0, curr_min = 0, ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			// add student i to current group that is not strong yet
			if (a[i] >= x) {
				++ans;
				continue;
			}
			++curr_num;
			curr_min = a[i];
			if (curr_num * curr_min >= x) { // valid group
				++ans;
				curr_num = 0;
			}
		}
		cout << ans << '\n';
	}
}