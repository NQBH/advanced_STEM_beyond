#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> r(n);
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}
		int m;
		cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int maxR = 0;
		int maxB = 0;
		int sum1 = 0;
		for (int x : r) {
			sum1 += x;
			maxR = max(sum1, maxR);
		}
		int sum2 = 0;
		for (int x : b) {
			sum2 += x;
			maxB = max(sum2, maxB);
		}
		cout << maxR + maxB << endl;
	}
}
