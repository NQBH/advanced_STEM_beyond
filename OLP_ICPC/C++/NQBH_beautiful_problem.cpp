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
		vector<int> a(n + 1), l(m + 1), r(m + 1);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= m; ++i) cin >> l[i] >> r[i];

	}
}
// unfinished