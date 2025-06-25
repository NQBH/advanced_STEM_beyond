#include <bits/stdc++.h>
using namespace std;

signed main() {
	long long n; cin >> n;
	cout << n << " ";
	for (; n != 1 ; (n % 2 == 0 ? n /= 2 : (n *= 3, n++)), cout << n << " " );
	return 0;
}