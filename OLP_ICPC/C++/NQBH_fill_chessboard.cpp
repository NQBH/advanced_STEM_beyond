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
		if (m == 0) {
			if (n % 2 == 0) cout << "YES\n";
			else cout << "NO\n";
		} else if (n == 2 && m == 1) cout << "NO\n";
		else if 

		else { // no constraints
			vector<int> x(m + 1), y(m + 1);
			for (int i = 1; i <= m; ++i) cin >> x[i] >> y[i];
		}
	}
}