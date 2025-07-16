#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int main() {
	int m, n, k, x, y;
	cin >> m >> n >> k;
	int ans = C(m + n - 2, m - 1);
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		ans -= C(x + y - 2, x - 1) * C(m + n - x - y, m - x);
	}
	cout << ans % mod;
}