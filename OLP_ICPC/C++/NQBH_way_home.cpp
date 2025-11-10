#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	int last = 0, ans = 0;
	bool ok = true;
	for (int i = 1; i < n; ++i)

		if (s[i] == '1') {
			if (i - last > d) ok = false;
			else {
				last = i;
				++ans;
			}
		}
	if (!ok) cout << "-1\n";
	else cout << ans << '\n';
}
// unfinished