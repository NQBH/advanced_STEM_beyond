#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, sum = 0;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] %= 3;
			sum += a[i];
		}
		if (sum % 3 ) cout << "0 0\n";
		else cout << "1 2\n";
	}
}