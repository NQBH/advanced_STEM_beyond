#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n & 1) {
		if (n % 3 == 0) cout << "6 " << n - 6 << '\n';
		else if (n % 3 == 1) cout << "4 " << n - 4 << '\n';
		else cout << "8 " << n - 8 << '\n';
	} else cout << "4 " << n - 4 << '\n';
}