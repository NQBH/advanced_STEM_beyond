#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		// cout << (n & 1 ? "3\n" : "2\n"); // 1st solution
		// cout << n << '\n'; // 2nd solution
		cout << "7\n";
	}
}