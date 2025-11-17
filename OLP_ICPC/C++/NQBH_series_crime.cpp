#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	map<int, int> fx, fy;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '*') {
				++fx[i];
				++fy[j];
			}
	}
	for (auto e : fx)
		if (e.second == 1) cout << e.first + 1 << ' ';
	for (auto e : fy)
		if (e.second == 1) cout << e.first + 1;
}