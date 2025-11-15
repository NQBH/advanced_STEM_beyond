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
		if ((a + b + c) & 1) cout << "-1\n";
		else if (a + b <= c) cout << a + b << '\n';
		else cout << (a + b + c) / 2 << '\n';
	}
}