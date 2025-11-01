#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		a[0] = 0;
		int num0 = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (!a[i]) ++num0;
		}
		if (num0 == n) cout << "0\n";
		else if (!num0) cout << "1\n";
		else {
			int num_nonzero_block = 0;
			for (int i = 1; i <= n; ++i)
				if (a[i] && !a[i - 1]) ++num_nonzero_block; 
			if (num_nonzero_block == 1) cout << "1\n";
			else cout << "2\n";
		}
	}
}