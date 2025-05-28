#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int quick_mod(int a, int n) {
	
	if (n == 0) return 1;
 
	int x = quick_mod(a, n / 2);
	x = x * x % MOD;
 
	if (n % 2 == 1) x = x * a % MOD;
	
	return x;
}
 
signed main() {
	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		cout << quick_mod(a % MOD, b % MOD) << "\n";
	}
}