#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		int ACC = 0;
		bool hv = false;
		for (int i = 0; i < k; ++i) {
			int x;
			cin >> x;
			ACC += x;
			if (x % 3 == 1) hv = true;
		}
		if (ACC % 3 == 0) cout << "0\n";
		else if (ACC % 3 == 2) cout << "1\n";
		else {
			if (hv) cout << "1\n";
			else cout << "2\n";
		}
	}
}