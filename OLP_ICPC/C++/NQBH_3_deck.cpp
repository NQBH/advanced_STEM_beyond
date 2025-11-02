#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << ((a + b + c) % 3 == 0 && a + c >= 2 * b ? "YES\n" : "NO\n");
	}
}