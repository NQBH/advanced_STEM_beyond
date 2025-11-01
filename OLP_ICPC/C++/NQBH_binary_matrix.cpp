#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, a;
		cin >> n >> m;
		vector<string> s(n);
		int r = 0, c = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
			a = 0;
			for (int j = 0; j < m; ++j) a ^= (s[i][j] == '1'? 1 : 0);
			if (a) ++r;
		}		
		for (int j = 0; j < m; ++j) {
			a = 0;
			for (int i = 0; i < n; ++i) a ^= (s[i][j] == '1'? 1 : 0);
			if (a) ++c;
		}
		cout << max(r, c) << '\n';
	}
}