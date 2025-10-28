#include <algorithm>
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
		int n, k, x;
		cin >> n >> k >> x;
		vector<int> a(n);
		set<int> s;
		for (int &x : a) {
			cin >> x;
			s.insert(x);
		}
		if (k - x == 1) { // if there is no empty position
			for (int i = 0; i <= x; ++i) cout << i << ' ';
			cout << '\n';
		} else if (n + k == x + 1) { // if number of empty position = k
			for (int i = 0; i <= x; ++i)
				if (!s.count(i)) cout << i << ' ';
			cout << '\n';
		} else {
			int max_dist = 0;
			sort(a.begin(), a.end());
			for (int i = 1; i < n; ++i) {
				int dist = a[i] - a[i - 1];
				max_dist = max(max_dist, dist);
			}
			

		}
	}
}