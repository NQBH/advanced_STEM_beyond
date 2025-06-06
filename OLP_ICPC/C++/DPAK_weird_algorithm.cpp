#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin >> n;
	cout << n << " ";
	for (; n != 1 ; (n % 2 == 0 ? n /= 2 : (n *= 3, n++)), cout << n << " " ) ;
	return 0;
}