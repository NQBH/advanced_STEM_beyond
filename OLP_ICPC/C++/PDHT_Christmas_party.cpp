#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAX 1000005
using namespace std;
ll der[MAX];
int main() {
	int n;
	cin >> n;
	der[1] = 0;
	if (n >= 2)
		der[2] = 1;
	for (int i = 3; i <= n; ++i)
		der[i] = (1ll * (i - 1) * (der[i - 1] + der[i - 2])) % MOD;
	cout << der[n] << '\n';
	return 0;
}