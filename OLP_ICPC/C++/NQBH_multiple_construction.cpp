#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << "1 1\n";
		else if (n == 2) cout << "1 2 1 2\n";
		else {
			vector<int> a(2 * n + 1, 0);
			a[1] = a[n + 1] = n;
			for (int i = 1; i < n; ++i) a[n + 1 - i] = a[n + 1 + i] = i;
			for (int i = 1; i <= 2 * n; ++i) cout << a[i] << ' ';
			cout << '\n';
		}
	}
}