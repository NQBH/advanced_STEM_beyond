#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		cout << (k % 3 == 1 ? "YES\n" : "NO\n");
	}
}