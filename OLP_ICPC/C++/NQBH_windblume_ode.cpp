#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		if (!isPrime(accumulate(a.begin(), a.end(), 0))) {
			cout << n << '\n';
			for (int i = 1; i <= n; ++i) cout << i << " \n"[i == n];
		} else { // sum sure odd
			cout << n - 1<< '\n';
			int i;
			for (i = 0; i < n; ++i)
				if (a[i] & 1) break;
			for (int j = 0; j < n; ++j)
				if (j != i) cout << j + 1 << ' ';
			cout << '\n';
		}
	}
}