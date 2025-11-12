#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		vector<int> cnt(n + 1, 0);
		int j = i;
		cnt[i] = 1;
		while (cnt[j] < 2) {
			j = p[j];
			++cnt[j];
		}
		cout << j << ' ';
	}
}