#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n + 1);
		vector<int> freq(101,0);
		for (int i = 1; i <= n; i++) { 
			cin >> a[i];
			freq[a[i]]++;
		}
		for (int i = 0; i <= 100; i++) {
			if (freq[i] == 0) {
				cout << i << endl;
				break;
			}
		}
	}
}