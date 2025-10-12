#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0, num0 = 0;
		cin >> n;
		vector<int> a(n);
		vector<bool> exist(101, false);
		for (int& x : a) {
			cin >> x;
			if (!exist[x]) exist[x] = true;
			if (x == 0) ++num0;
		}
		if (num0 == 0) cout << 0 << '\n';
		else {
			for (int i = 1; i <= 100; ++i)
				if (!exist[i]) {
					ans = i;
					break;
				}
			cout << ans << '\n';
		}
	}
}