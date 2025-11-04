#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int k, x;
		cin >> k >> x;
		cout << (x << k) << '\n';
	}
}