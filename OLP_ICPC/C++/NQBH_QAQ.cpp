#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size(), ans = 0;
	vector<int> pnQ(n, 0), snQ(n, 0);
	pnQ[0] = (s[0] == 'Q');
	snQ[n - 1] = (s[n - 1] == 'Q');
	for (int i = 1; i < n; ++i)
		pnQ[i] = pnQ[i - 1] + (s[i] == 'Q');
	for (int i = n - 2; i >= 0; --i)
		snQ[i] = snQ[i + 1] + (s[i] == 'Q');
	for (int i = 1; i < n - 1; ++i)
		if (s[i] == 'A') ans += pnQ[i - 1] * snQ[i + 1];
	cout << ans;
}