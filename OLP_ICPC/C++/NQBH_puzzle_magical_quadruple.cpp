#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, count = 0;
	long long k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	// naive approach
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int p = 1; p <= n; ++p)
				for (int q = 1; q <= n; ++q) {
					if ((a[i] & a[j] & a[p] & a[q]) == 0) ++count;
					if (count == k) {
						cout << i << " " << j << " " << p << " " << q;
						return 0;
					}
				}
	cout << -1;
	/*
	// bitmask
	for (int mask = 0; mask < (1 << n); mask++) {
		
	}
	*/
}