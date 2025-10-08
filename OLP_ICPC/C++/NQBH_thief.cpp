// https://oj.vnoi.info/problem/icpc24_mt_a
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, W, h, max_value = 1e5;
	cin >> n >> W >> h;
	vector<int> w(n + 1), c(n + 1);
	for (int i = 1; i <= n; ++i) cin >> w[i] >> c[i];
	// f[i][j][k] = minimum total weight in the bag after considering 1st i items, with sum values = j, & hand kth item, k <= i
	vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(max_value + 1, vector<int>(n + 1, INT_MAX)));
	f[0][0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= max_value; ++j) {
			if (w[i] <= h && j >= c[i]) f[i][j][i] = f[i - 1][j - c[i]][0]; // hand ith item
			for (int k = 1; k <= i; ++k) {
				f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]); // skip ith item
				if (j >= c[i]) f[i][j][k] = min(f[i][j][k], f[i - 1][j - c[i]][k] + w[i]); // take ith item into the bag				
			}
		}
	int ans = 0;
	for (int j = 0; j <= max_value; ++j)
		for (int k = 1; k <= n; ++k)
			if (f[n][j][k] <= W) {
				ans = j;
				continue;
			}
	cout << ans << '\n';
}