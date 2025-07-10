#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// compute combination C_n^k
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int main() {
	int m, n, k, diff, ans = 0;
	// cin >> n >> m >> k;
	m = 3; k = 2;
	cin >> n;
	vector<int> a(n), a_compressed(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	// compress vector a to reduce its values but still preserve invariance
	a_compressed[0] = 0;
	for (int i = 1; i < n; ++i) {
		diff = a[i] - a[i - 1];
		if (diff <= k) a_compressed[i] = a_compressed[i - 1] + diff;
		else a_compressed[i] = a_compressed[i - 1] + k + 1;
	}

	// compute frequency/number of appearances of i in vector a_compress
	vector<int> freq(a_compressed[n - 1] + 1);
	for (int i = 0; i < n; ++i) ++freq[a_compressed[i]];
	/* DEBUG
	cout << "freq: ";
	for (int i = 0; i <= a_compressed[n - 1]; ++i) cout << freq[i] << " ";
		cout << "\n"; */

	// dynamic programming dp_max[i] := number of m-tuples s.t. maximum value = i
	vector<int> dp_max(a_compressed[n - 1], 0);
	vector<vector<int>> comb(n, vector<int>(m, -1)); // 2D vector stored computed C_n^k
	// compute dp_max[0] = C_{f[0]}^k if f[0] >= k, dp_max[0] = 0 if f[0] < k
	if (freq[0] < k) dp_max[0] = 0;
	else if (freq[0] == k) dp_max[0] = 1;
	else dp_max[0] = C(freq[0], k);

	/* 1st sol
	for (int i = 1; i <= a_compressed[n - 1]; ++i) {
		int sum = 0;
		// compute sum_prev_k_freq[i] := f[i - 1] + f[i - 2] + ... + f[i - k]
		vector<int> sum_prev_k_freq(n);
		if (i < k) sum += freq[i - 1];
		else sum += freq[i - 1] - freq[i - k - 1];
		sum_prev_k_freq[i] = sum;
		// cout << "sum_prev_k_freq[" << i << "] = " << sum;

		// compute dp_max[i]
		int a, b;		
		for (int j = 1; j <= min(m, freq[i]); ++j) {
			// if (comb[freq[i]][j] == -1) comb[freq[i]][j] = C(freq[i], j);
			a = C(freq[i], j);
			//if (comb[sum_prev_k_freq[i]][m - j] == -1) comb[sum_prev_k_freq[i]][m - j] == C(sum_prev_k_freq[i], m - j);
			b = C(sum_prev_k_freq[i], m - j);
			dp_max[i] += a * b;
		}
		// cout << "dp_max[" << i << "] = " << dp_max[i];
		ans += dp_max[i];
	}
	*/

	// 2nd sol
	for (int i = 0; i <= a_compressed[n - 1]; ++i) {
		// compute dp_max[i] = C_{f[i] + f[i - 1] + ... + f[i - k]}^m - C_{f[i - 1] + ... + f[i - k]}^m
		int sum = 0;
		for (int j = max(0, i - k); j <= i - 1; ++j) {
			sum += freq[j];
		}
		//cout << "sum = " << sum;
		dp_max[i] = C(sum + freq[i], m) - C(sum, m);
		//cout << "dp_max[" << i << "] = " << dp_max[i];
		ans += dp_max[i];
	}
	//*/
	cout << ans;
}