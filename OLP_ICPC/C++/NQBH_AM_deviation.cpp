#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		cout << ((a1 + a2 + a3) % 3 == 0? "0\n" : "1\n");
	}
}