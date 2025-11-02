#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n - k; i++) cout << 0;
		for (int i = 0; i < k; i++) cout << 1;
		cout << '\n';
	}
}