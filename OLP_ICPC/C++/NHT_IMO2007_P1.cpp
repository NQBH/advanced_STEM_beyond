#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int N = 1000005;
int n;
ld a[N], x[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> x[i];

	ld d = -1e18;
	int pos_i = -1, pos_j = -1;
	ld max_prev = a[1];
	for (int i = 2; i <= n; ++i) {
		if (max_prev - a[i] > d) {
			d = max_prev - a[i];
			pos_i = i;
			for (int j = 1; j < i; ++j) {
				if (a[j] == max_prev) {
					pos_j = j;
					break;
				}
			}
		}
		max_prev = max(max_prev, a[i]);
	}

	ld max_diff = 0;
	for (int i = 1; i <= n; ++i)
		max_diff = max(max_diff, abs(x[i] - a[i]));

	if (max_diff >= d / 2) {
		cout << "YES\nmax|x_i - a_i| = " << fixed << setprecision(10)
		     << max_diff << " ; d / 2 = " << d / 2 << '\n';
	} else {
		cout << "NO\n";
		return 0;
	}
	
	x[pos_j] = (a[pos_i] + a[pos_j]) / 2;

	for (int k = pos_j + 1; k <= n; ++k)
		x[k] = max(x[k - 1], a[k] - d / 2);

	for (int k = pos_j - 1; k >= 1; --k)
		x[k] = min(x[k + 1], a[k] + d / 2);

	max_diff = 0;
	for (int i = 1; i <= n; ++i)
		max_diff = max(max_diff, abs(x[i] - a[i]));

	for (int i = 1; i <= n; ++i)
		cout << fixed << setprecision(10) << x[i] << " ";
	cout << '\n';
	cout << "max|x[i] - a[i]| = " << fixed << setprecision(10) << max_diff
	     << " = d/2 = " << d / 2 << '\n';

	return 0;
}