#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int P = 1;
		bool okP = true;
		for (int i = 1; i <= k; ++i) {
			P *= 2;
			if (P >= n + 1) {
				okP = false;
				break;
			}
		}
		cout << (okP ? P : n + 1) << '\n';
	}
}