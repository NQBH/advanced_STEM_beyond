#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		vector<int> a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		for (int i = 0; i < 5; ++i) {
			++a[0];
			if (a[0] > a[1]) sort(a.begin(), a.end());
		}
		cout << a[0] * a[1] * a[2] << '\n';
	}
}