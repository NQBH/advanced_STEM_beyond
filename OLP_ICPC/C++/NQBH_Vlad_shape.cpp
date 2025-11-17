#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, n1;
		cin >> n;
		vector<string> s(n);
		set<int> a;
		for (int i = 0; i < n; ++i) {
			n1 = 0;
			cin >> s[i];
			n1 = count(s[i].begin(), s[i].end(), '1');
			if (a.size() < 2 && n1) a.insert(n1);
		}
		cout << (a.size() == 1 ? "SQUARE\n" : "TRIANGLE\n");
	}
}