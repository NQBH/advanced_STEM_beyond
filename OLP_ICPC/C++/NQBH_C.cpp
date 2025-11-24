#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	set<int> S;
	map<int, int> f;
	for (int &x : a) {
		cin >> x;
		S.insert(x);
		++f[x];
	}
	int max_del = 0;
	for (auto e : f)
		if (e.second > 1) max_del += e.second - 1;
	if (k <= max_del) cout << S.size();
	else cout << S.size() - (k - max_del);
	return 0;
}