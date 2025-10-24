#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		while (q--) {
			int a, ans = 0;
			cin >> a;
			bool stop = false;
			while (a) {
				for (int i = 0; i < n; ++i) {
					if (s[i] == 'A') {
						--a;
					} else {
						a = a / 2;
					}
					++ans;
					if (a == 0) {
						stop = true;
						break;
					}
				}
				if (stop) break;
			}
			cout << ans << '\n';
		}
	}
}
// TLE