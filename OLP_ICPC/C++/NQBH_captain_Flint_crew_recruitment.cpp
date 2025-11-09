#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n <= 30) cout << "NO\n";
		else {
			int a = n - 30;
			if (a == 6 || a == 10 || a == 14) cout << "YES\n6 10 15 " << n - 31 << '\n';
			else cout << "YES\n6 10 14 " << a << '\n';
		}
	}
}