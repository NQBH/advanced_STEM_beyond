#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1 or n == 3) cout << -1 << endl;
		else if (n % 2 == 0) {
			cout << string(n - 2, '33') << "66" << endl;
		}
		else {
			cout << string(n - 5, '33') << "36366" << endl;
		}
	}
}
