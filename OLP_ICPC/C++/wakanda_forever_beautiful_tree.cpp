#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 2) {
			cout << -1 << '\n';
			continue;
		}
		if (n == 3) {
			cout << "1 3\n2 3\n";
			continue;
		}
		if (n == 4) {
			cout << "1 2\n3 1\n4 1\n";
			continue;
		}
		cout << "1 2\n";
		cout << "2 3\n";
		cout << "3 4\n";
		cout << "1 " << n << '\n';
		for (int i = 5; i < n; i++) cout << 2 << ' ' << i << '\n';
	}
}