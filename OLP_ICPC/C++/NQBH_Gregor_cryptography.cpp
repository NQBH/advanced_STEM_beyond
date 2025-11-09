#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int p;
		cin >> p;
		cout << "2 " << p - 1 << '\n';
	}
}