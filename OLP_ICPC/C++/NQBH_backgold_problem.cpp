#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n & 1) {
		cout << n / 2 << '\n';
		for (int i = 0; i < (n - 3) / 2; ++i) cout << "2 ";
		cout << 3;
	} else {
		cout << n / 2 << '\n';
		for (int i = 0; i < n / 2; ++i) cout << "2 ";
	}
}