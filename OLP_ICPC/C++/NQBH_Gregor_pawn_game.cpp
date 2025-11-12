#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		string E, G;
		cin >> n >> E >> G;
		int nE1 = 0, nG1 = 0;
		for (int i = 0; i < n; ++i) {
			if (E[i] == '1') ++nE1;
			if (G[i] == '1') ++nG1;
		}
		if (nE1 == 0) {
			cout << nG1 << 'n';
			continue;
		}
		if (nG1 == 0) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < n; ++i) {
			if (E[i] == '0' && G[i] == '1') {
				++ans;
				E[i] = '2'; // done
			} else if (E[i] == '1')
		}
	}

}