
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		map<int, int> ma;
		for (int i = 0; i < k; i++) {
			int b, c; cin >> b >> c;
			ma[b] += c;
		}
		vector<int> a;
		for (auto it : ma) {
			a.push_back(it.second);
		}
 
		sort(a.begin(), a.end(), greater<int>());
		int total = 0;
		for (int i = 0; i < min(n,(int)a.size()); i++) {
			total += a[i];
		}
		cout << total << endl;
	}
}
