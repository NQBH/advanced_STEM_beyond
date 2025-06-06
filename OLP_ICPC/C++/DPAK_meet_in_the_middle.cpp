#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

int n, x;
int res = 0;
int mid;

vector<int> a;
vector<int> ma;

void backTracking(int i, int total) {
	if (total > x) {
		return;
	}

	if (i > mid) {
		ma.push_back(total);
		return;
	}

	backTracking(i + 1, total);
	backTracking(i + 1, total + a[i]);
}

void findingNemo(int i, int total) {
	if (total > x) {
		return;
	}
	if (i > n) {
		int left = x - total;
		int rightIndex = -1;

		int l = 0, r = ma.size() - 1;
		while (l <= r) {
			int m = l + r >> 1;
			if (ma[m] == left) {
				rightIndex = m;
				l = m + 1;
			}
			else if (ma[m] > left) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		int leftIndex = -1;
		l = 0, r = ma.size() - 1;
		while (l <= r) {
			int m = l + r >> 1;
			if (ma[m] == left) {
				leftIndex = m;
				r = m - 1;
			}
			else if (ma[m] > left) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		if (leftIndex == -1 || rightIndex == -1) {
			return;
		}

		res += rightIndex - leftIndex + 1;
		return;
	}

	findingNemo(i + 1, total);
	findingNemo(i + 1, total + a[i]);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	a.resize(n + 1);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}
	mid = n / 2;
	backTracking(1, 0);

	cout << endl;
	sort(ma.begin(), ma.end());

	findingNemo(mid + 1, 0);

	cout << res;
}