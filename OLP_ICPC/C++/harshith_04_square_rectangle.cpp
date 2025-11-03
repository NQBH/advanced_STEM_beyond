#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	int l1, b1, l2, b2, l3, b3;

	auto check = [&] () {
		if (l1 == l2 && l2 == l3) return (l1 == b1 + b2 + b3 || (b1 == b2 + b3 && 2 * l1 == b1));
		if (l2 == l3) return (b2 + b3 == b1 && b1 == l2 + l1);
		return false;
	};

	while (t--) {
		cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
		if (check()) cout << "YES\n";
		else {
			swap(l1, b1); swap(l2, b2); swap(l3, b3);
			if (check()) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}