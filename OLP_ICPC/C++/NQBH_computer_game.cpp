#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string x, y;
		cin >> n >> x >> y;
		bool ok = true;
		for (int i = 0; i < n; ++i)
			if (x[i] == '1' && y[i] == '1') {
				ok = false;
				break;
			}
		cout << (ok ? "YES\n" : "NO\n");
	}
}