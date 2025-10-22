#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		cout << "t = " << t << '\n';
		int n;
		cin >> n;
		vector<int> a(n + 1, 0);
		int diff_odd_even = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] & 1) ++diff_odd_even;
			else --diff_odd_even;
		}
		if (n == 1) cout << 0 << '\n';
		else if (n & 1) {
			int ans = 0, pos;
			if (abs(diff_odd_even) != 1) cout << -1 << '\n';
			else {
				if (diff_odd_even == 1) { // O, E, O, E, ..., O
					for (int i = 1; i <= n; ++i) {
						if ((i & 1) && !(a[i] & 1)) {
							pos = i;
							while (!(a[pos] & 1)) {
								++pos;
								++ans;
							}
							swap(a[i], a[pos]);
						}
						if (!(i & 1) && (a[i] & 1)) {
							pos = i;
							while ((a[pos] & 1)) {
								++pos;
								++ans;
							}
							swap(a[i], a[pos]);
						}
					}
				} else { // E, O, E, ..., E
					for (int i = 1; i <= n; ++i) {
						if ((i & 1) && (a[i] & 1)) {
							pos = i;
							while ((a[pos] & 1)) {
								++pos;
								++ans;
							}
							swap(a[i], a[pos]);
						}
						if (!(i & 1) && !(a[i] & 1)) {
							pos = i;
							while (!(a[pos] & 1)) {
								++pos;
								++ans;
							}
							swap(a[i], a[pos]);
						}
					}
				}
			}
			cout << ans << '\n';
		} else { // n even
			if (abs(diff_odd_even)) cout << -1 << '\n';
			else {
				// O E O E ... E


				// E O E O ... O

			}
		}

	}
}