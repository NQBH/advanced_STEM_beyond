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
		vector<int> x(n);
		set<int> a;
		for (int &i : x) cin >> i;
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				a.insert(x[j] - x[i]);
		cout << a.size() << '\n';
	}
}