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
		for (int i = 0; i < k; ++i) cout << 1;
		for (int i = 0; i < n - k; ++i) cout << 0;
		cout << '\n';
	}
}