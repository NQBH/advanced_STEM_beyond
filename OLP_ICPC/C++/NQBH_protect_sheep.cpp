#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int r, c;
	cin >> r >> c;
	vector<string> a(r);
	int nW = 0;
	for (int i = 0; i < r; ++i) {
		cin >> a[i];
		for (char c : a[i])
			if (c == 'W') ++nW;
	}
	if (!nW) {
		cout << "YES\n";
		for (string s : a) cout << s << '\n';
	} else {
		int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
		bool ok = true;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (a[i][j] == 'W') {
					for (int k = 0; k < 4; ++k) {
						int ni = i + dx[k], nj = j + dy[k];
						if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
							if (a[ni][nj] == 'S') {
								ok = false;
								break;
							}
						}
					}
				} else if (a[i][j] == '.') a[i][j] = 'D';
			}
			if (!ok) break;
		}
		if (!ok) cout << "NO";
		else {
			cout << "YES\n";
			for (string s : a) cout << s << '\n';
		}
	}
}