#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int& v : a) cin >> v;
		if (n == 3) {
			sort(a.begin(), a.end());
			if (a[0] == a[1] && a[2] < 2 * a[0]) cout << 2 * a[0] + a[2] << '\n';
			else cout << 0 << '\n';
		} else { // n >= 4
			int ans = 0, so_canh_day = 0, so_canh_bang = 0;
			sort(a.begin(), a.end());
			int freq = 1;
			for (int i = n - 1; i >= 1; --i) {
				if (a[i] == a[i - 1]) {
					++freq;
					continue;
				} else { // a[i] != a[i - 1]
					if (freq == 1 && so_canh_day < 2) {
						ans += a[i];
						++so_canh_day;
					}
					else if (freq % 2 == 0) { // khong chon them canh day
						ans += freq * a[i];
						so_canh_bang += freq;
					}
					else if (freq % 2 != 0 && so_canh_day < 2) {
						ans += freq * a[i];
						++so_canh_day;
					}
					freq = 1;
				}
			}
			if (so_canh_day + so_canh_bang <= 2) cout << 0 << '\n';
			// consider more fail cases . . .	
			else cout << ans << '\n';
		}
	}
}