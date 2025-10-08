#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		int num_locked_pos = 0, num_nonnegative_pos = 0;
		cin >> n;
		vector<int> a(n + 1), l(n + 1), ps(n + 1, 0), a_unlock;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] >= 0) ++num_nonnegative_pos;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> l[i];
			if (l[i]) ++num_locked_pos;
		}
		if (num_locked_pos >= n - 1 || num_nonnegative_pos == n) // cannot change initial array a
			for (int i = 1; i <= n; ++i) cout << a[i] << " ";
		else { // at least 2 unlocked positions
			for (int i = 1; i <= n; ++i)
				if (!l[i]) a_unlock.push_back(a[i]);
			sort(a_unlock.begin(), a_unlock.end(), [](int a, int b) {return a > b;});
			int idx = 0;
			for (int i = 1; i <= n; ++i) {
				if (l[i]) cout << a[i] << " ";
				else cout << a_unlock[idx++] << " ";
			}			
		}
		cout << '\n';
	}
}