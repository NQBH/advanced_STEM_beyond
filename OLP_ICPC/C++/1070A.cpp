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
		vector<int> a(n);
		for (int &x : a) cin >> x;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		int curr_max = -1, nrm = 0;
		for (int x : a)
			if (x < curr_max) ++nrm;
			else curr_max = x;
		cout << nrm << '\n';
	}
}