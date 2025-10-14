#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int>a(n + 1), b(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		a[1] = 1;
		int num = 1;

		for (int i = 2; i <= n; i++) {
			int calc = b[i] - b[i - 1];
			if (i - calc == 0) {
				num++;
				a[i] = num;
			}
			else {
				a[i] = a[i - calc];
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

/*
1 2 3 7 12

4 4 4 1 2 2

[3 + 3 + 3 + 2 + 1 + 1]
*/