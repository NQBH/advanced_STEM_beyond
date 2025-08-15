#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	int a[n], b[m];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] - k <= b[j] && b[j] <= a[i] + k) { // ith applicant receives jth apartment
			++ans;
			++i;
			++j;
		}
		else if (b[j] < a[i] - k) ++j;
		else ++i;
	}
	cout << ans;
}