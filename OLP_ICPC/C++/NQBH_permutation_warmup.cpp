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
		if (n & 1) cout << (n * n + 3) / 4 << '\n';
		else cout << n * n / 4 + 1 << '\n';		
	}
}