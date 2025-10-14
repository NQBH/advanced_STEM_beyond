#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 0) {
			cout << "Yes" << endl;
			continue;
		}
		vector<int> a;

		for ( ; n > 0 ; a.push_back(n % 2), n /= 2);

		for (int i = 0; a[i] == 0; a.push_back(a[i++]));

		bool check = (a.size() % 2 == 1 ? (a[a.size() / 2] == 0 ? true : false) : true);

		for (int i = 0; i < a.size() / 2; i++) {
			if (a[i] != a[a.size() - i - 1]) {
				check = false;
				break;
			}
		}

		cout << (check ? "Yes" : "No") << endl;
	}
}
/*
x = reverse(f[x])
x ^ f[x] = n
yynn^nnyy = [y^n y^n n^y n^y]

0
1
010 : 2 : T
11 : 3 10 ^ 01 : T
00100 : 4 : F
101 : 5 = 100 ^ 001 : T
0110 : 6 = 1011 ^ 1101 : T
111 : 7 : F
1000 : 8 : F
1001 : 9 : T
01010 : 10 : T
1011 : 11 : F
*/