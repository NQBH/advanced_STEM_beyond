#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		set<int> s;
		for (int& x : a) {
			cin >> x;
			s.insert(x);
		}
		if (s.size() == n) {
			for (int i = 0; i < k; ++i) cout << a[i % 3] << ' ';
			cout << '\n';
		} else {
			vector<int> b(3);
			for (int i = 1; i <= n; ++i)
				if (!s.count(i)) {
					b[0] = i;
					break;
				}
			b[2] = a[n - 1];
			for (int i = 1; i <= n; ++i)
				if (i != b[0] && i != b[2]) {
					b[1] = i;
					break;
				}
			for (int i = 0; i < k; ++i) cout << b[i % 3] << ' ';
			cout << '\n';
		}		
	}
}