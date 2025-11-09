#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		cout << (m % n == 0 ? "YES\n" : "NO\n");
	}
}