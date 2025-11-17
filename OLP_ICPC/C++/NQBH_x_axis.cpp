#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		vector<int> x(3);
		for (int &i : x) cin >> i;
		sort(x.begin(), x.end());
		cout << x[2] - x[0] << '\n';
	}
}