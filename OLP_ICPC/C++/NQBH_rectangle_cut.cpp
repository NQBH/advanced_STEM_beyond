#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if ((a & 1) && (b & 1)) cout << "NO\n";
		else if ((b == 2 * a && (a & 1)) || (a == 2 * b && (b & 1))) cout << "NO\n";
		else cout << "YES\n";
	}
}