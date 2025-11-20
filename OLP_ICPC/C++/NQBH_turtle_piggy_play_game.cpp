#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << __lg(r) << '\n';
	}
}