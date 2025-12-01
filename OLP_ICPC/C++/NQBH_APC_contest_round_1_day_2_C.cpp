#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	// ABAB...
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i)
		if ((i & 1) && s[i] == 'A') ++a;
		else if (!(i & 1) && s[i] == 'B') ++a;
	// BABA...
	for (int i = 0; i < n; ++i)
		if ((i & 1) && s[i] == 'B') ++b;
		else if (!(i & 1) && s[i] == 'A') ++b;
	cout << min(a, b);
}