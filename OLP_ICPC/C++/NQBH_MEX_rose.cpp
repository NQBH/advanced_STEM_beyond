#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n >> k;
		vector<int> a(n), occupied(n + 1, 0);
		for (int& i : a) {
			cin >> i;
			if (i <= k) ++occupied[i];
		}
		for (int i = 0; i < k; ++i)
			if (occupied[i] == 0) ++ans;
		cout << max(ans, occupied[k]) << '\n';
	}
}