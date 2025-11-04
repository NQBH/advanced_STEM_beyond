#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		if ((n ^ b) & 1) cout << "NO\n";
		else {
			if (a > b && (n ^ a) & 1) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}