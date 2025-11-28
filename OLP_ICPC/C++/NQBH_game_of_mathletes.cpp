#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		vector<bool> visited(n + 1, false);
		map<int, int> f;
		for (int &x : a) {
			cin >> x;
			++f[x];
		}
		int n_pair = 0;
		if (!(k & 1) && f[k / 2]) {
			n_pair += f[k / 2] / 2;
			visited[k / 2] = true;
		}
		for (auto e : f)
			if (!visited[e.first]) {
				int a = k - e.first;
				if (a >= 1 && a <= n && f[a]) { // take pair (e.first, a)
					n_pair += min(f[e.first], f[a]);
					visited[e.first] = true;
					visited[a] = true;
				}
			}
		cout << n_pair << '\n';
	}
}