#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0, num_negative = 0;
		vector<int> a(n);
		for (int& v : a) {
			cin >> v;
			if (v == -1) ++num_negative;
			else if (v == 0) ++ans;
		}
		ans += 2 * (num_negative % 2);
		cout << ans << '\n';
	}
}