#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {


	int t; cin >> t;
	while (t--) {
		int xc, yc, k;
		cin >> xc >> yc >> k;
		if (k == 1) {
			cout << xc << " " << yc << endl;
		}
		else {
			int tmp_bot = xc - 1;
			int tmp_top = xc + 1;
			int len_bot = k / 2;
			int len_top = k / 2;

			int sum_bot = 0, sum_top = 0;

			for (int i = 0; i < len_bot; i++) {
				
				cout << tmp_bot << " " << yc << endl;
				sum_bot += tmp_bot--;
			}
			for (int i = 0; i < len_top; i++) {
				cout << tmp_top << " " << yc << endl;
				sum_bot += tmp_top++;
			}

			if (k % 2 == 1) {
				int last_x = k * xc - sum_bot;
				cout << last_x << " " << yc << endl;
			}

		}
	}
	return 0;
}