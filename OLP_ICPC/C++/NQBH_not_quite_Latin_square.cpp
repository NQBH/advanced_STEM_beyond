#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		vector<vector<char>> a(3, vector<char>(3));
		map<char, int> f;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {
				cin >> a[i][j];
				if (a[i][j] != '?') ++f[a[i][j]];
			}
		if (f['A'] < 3) cout << "A\n";
		else if (f['B'] < 3) cout << "B\n";
		else cout << "C\n";
	}
}