#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		bool ok = true;
		cin >> n;
		vector<int> b(n), freq(n + 1, 0); // freq[i] = frequency of i in array b
		for (int& x : b) {
			cin >> x;
			++freq[x];
		}
		for (int i = 1; i <= n; ++i)
			if (!freq[i] && freq[i] % i) { // already forces freq[n] in {0, n}
				cout << "-1\n";
				ok = false;
			}
		if (!ok) continue;
		if (b[0] == n) { // b = n n ... n then a can be taken as 1 1 ... 1 (or any n same value in [n])
			for (int i = 0; i < n; ++i) cout << 1 << " ";
			cout << '\n';
			continue;
		} else {
			vector<int> used(n + 1); // used[i] = current frequency of i used in array a
			int val = 1; // current value assigned to a[i]
			for (int i = 0; i < n; ++i) {
				
			}
		}

	}
}