#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, ans = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') ++cnt0;
			else { // s[i] == 1
				if (cnt1 == 0) ++ans;
				else {
					if (cnt0 >= k - 1) ++ans; // protect this 1
				}
				++cnt1;
				cnt0 = 0;
			}
		}
		if (!cnt1) cout << "0\n";
		else cout << ans << '\n';
	}
}