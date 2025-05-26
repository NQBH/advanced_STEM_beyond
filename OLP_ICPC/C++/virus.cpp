#include <bits/stdc++.h>
#define kmax 200000
#define mod 1000000007
#define ll long long
using namespace std;
ll F[kmax + 2], ans;
int t, n, k;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		F[1] = F[2] = 1;
		ans = 2;
		for (int i = 3; i <= 2*k; ++i) {
			F[i] = (F[i-1] + F[i-2]) % mod;
			if (i % 2 == 0)
				ans = (ans + F[i]) % mod;
		}
		cout << (ans * n) % mod << "\n";
	} 
	return 0;
}