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
		vector<int> a(n), b, c;
		for (int &x : a) cin >> x;
		int a_max = *max_element(a.begin(), a.end()), a_min = *min_element(a.begin(), a.end());
		if (a_max == a_min) {
			cout << "-1\n";
			continue;
		}
		for (int i : a)
			if (i == a_max) c.push_back(i);
			else b.push_back(i);
		cout << b.size() << ' ' << c.size() << '\n';
		for (int i : b) cout << i << ' ';
		cout << '\n';
		for (int i : c) cout << i << ' ';
		cout << '\n';		
	}
}