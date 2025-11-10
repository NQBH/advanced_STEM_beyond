#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << (((n + 1) / 2 - (n - k + 1) / 2) & 1 ? "NO\n" : "YES\n");		
	}
}