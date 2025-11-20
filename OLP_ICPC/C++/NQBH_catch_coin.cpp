#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		cout << (y >= -1 ? "YES\n" : "NO\n");
	}
}