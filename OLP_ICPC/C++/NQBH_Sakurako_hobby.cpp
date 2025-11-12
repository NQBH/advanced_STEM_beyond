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
		vector<int> p(n + 1, 0), parent(n + 1, 0);
		map<int, int> F;
		for (int i = 1; i <= n; ++i) cin >> p[i];
		string s;
		cin >> s;
		s = " " + s;
		for (int i = 1; i <= n; ++i) {
			// compute F(i)			
			if (p[i] == i) cout << (s[i] == '0' ? "1 " : "0 ");
			else if (parent[i]) cout << F[parent[i]] << ' ';
			else {
				parent[i] = i;
				int j = i;
				if (s[i] == '0') ++F[i];
				while (p[j] != i) {
					j = p[j];
					parent[j] = i;
					if (s[j] == '0') ++F[i];
				}
				cout << F[i] << ' ';
			}
		}
		cout << '\n';
	}
}