#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		bool nonincreasing = false;
		for (int i = 0; i < m; ++i) {
			cin >> a[i];
			if (i && a[i] == 1) nonincreasing = true;
		}
		if (nonincreasing) cout << 1 << '\n';
		else cout << n - a[m - 1] + 1 << '\n';
	}
}