#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		if (n == 0)
			break;
		int a, b;
		double ans = 1e9;
		for (int i = 1; i <= n; ++i) {
			cin >> a >> b;
			if (b >= 0 && (b + 4.5 / a * 3600) < ans)
				ans = b + 4.5 / a * 3600;
		}
		if ((int)ans != ans)
			++ans;
		cout << (int)ans << '\n';
	}

	return 0;
}