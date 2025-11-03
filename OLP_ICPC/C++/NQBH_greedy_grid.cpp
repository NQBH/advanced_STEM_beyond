#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (m == 1 || n == 1 || (m == 2 && n == 2)) cout << "NO\n";
		else cout << "YES\n";
	}
}