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
		vector<int> w(n + 1);
		for (int i = 1; i <= n; ++i) cin >> w[i];
		vector<vector<int>> a(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) cin >> a[i][j];
		if (m == 1) {

		} else {
			
		}
	}
}