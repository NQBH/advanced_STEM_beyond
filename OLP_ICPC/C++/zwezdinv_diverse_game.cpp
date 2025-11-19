#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tests;
    cin >> tests;
    while (tests--) {
    	int n, m;
    	cin >> n >> m;
    	vector<vector<int>> a(n, vector<int>(m));
    	for (auto &i : a)
    		for (auto &j: i) cin >> j;
    	if (n * m == 1) cout << "-1\n";
    	else {
    		for (int i = 0; i < n; ++i) {
    			for (int j = 0; j < m; ++j)
    				cout << a[(i + 1) % n][(j + 1) % m] << ' ';
    			cout << '\n';
    		}
    	}
    }
}