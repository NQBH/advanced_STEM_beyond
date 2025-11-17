#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		vector<int> x(3), y(3);
		for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];
		if (y[0] == y[1] && y[0] > y[2]) cout << abs(x[0] - x[1]) << '\n';
		else if (y[1] == y[2] && y[1] > y[0]) cout << abs(x[1] - x[2]) << '\n';
		else if (y[2] == y[0] && y[2] > y[1]) cout << abs(x[2] - x[0]) << '\n';
		else cout << "0\n";
	}
}