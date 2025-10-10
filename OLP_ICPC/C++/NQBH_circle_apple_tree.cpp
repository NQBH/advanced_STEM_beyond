#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> b(n);
		for (int& v : b) cin >> v;
		sort(b.begin(), b.end());
		int ans = 1;
		for (int i = 1; i < n; ++i)
			if (b[i] != b[i - 1]) ++ans;
		cout << ans << '\n';
	}
}