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
		vector<int> l(m), r(m);
		for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
		// find a common point so that mex(M) = 0
		int common_pos = -1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < m; ++i)
				if (i < l[j] || r[j] < i) break;
				else {
					if (j == m - 1) common_pos = i;
				}
		}
		if (common_pos != -1) {
			cout << "ok";
		}
		// mex(M) = 1

		// mex(M) = 2
	}
}