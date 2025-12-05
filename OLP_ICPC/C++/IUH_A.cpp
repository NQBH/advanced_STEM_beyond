#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, ans = 0;
	cin >> a >> b;
	vector<int> pp(b + 1, 1), f(b + 1, 0); // pp[n] = product of distinct primes of n
	for (int i = 2; i <= b; ++i)
		if (pp[i] == 1)
			for (int j = i; j <= b; j += i) pp[j] *= i;
	// for (int i = 1; i <= b; ++i) cout << pp[i] << ' ';
	for (int i = a; i <= b; ++i) {
		int a = pp[i];
		++f[a];
		if (f[a] > ans) ans = f[a];
	}
	cout << ans << '\n';
}