#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n + 1, 0), pos(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			pos[p[i]] = i;
		}
		if (pos[1] != 1 && pos[1] != n) {
			cout << "NO\n";
			continue;
		}
		bool no = false;
		int l = pos[n], r = pos[n];
		for (int i = n - 1; i > 1; --i) {
			if (pos[i] != l - 1 && pos[i] != r + 1) {
				no = true;
				break;
			} else if (pos[i] == l - 1) --l;
			else ++r;
		}
		if (no) cout << "NO\n";
		else cout << "YES\n";
	}
}