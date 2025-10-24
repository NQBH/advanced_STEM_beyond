#include <algorithm>
#include <iostream>
#include <map>
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
		map<int, int> freq; // frequency
		set<int> A;
		int num1 = 0;
		for (int &x : a) {
			cin >> x;
			++freq[x];
			if (x == 1) ++num1;
			A.insert(x);
			// if (x > a_max) a_max = x;
		}
		if (num1 > k) { // cannot erase all 1s
			cout << 1 << '\n';
			continue;
		}
		/*
		if (num1 == k) { // erase all 1s NOT DONE

			for (int &x : a) {
				if (x > 1) ans = 
			}
		}
		*/

		// find all divisors of a[i]
		set<int> divisor;
		for (int x : A)
			for (int d = 1; d <= x; ++d)
				if (x % d == 0) divisor.insert(d);
		sort(divisor.rbegin(), divisor.rend());
		// cout << "divisor = ";
		// for (int x : divisor ) cout << x << ' ';
		int ans = 1; // worst case
		for (int d : divisor) { // check if d can be beauty or not
			int num_erase = 0;
			for (auto [x, f] : freq)
				if (x % d != 0 && x < 4 * d) num_erase += f; // x must be >= 3d to apply Split
			if (num_erase <= k) {
				ans = d;
				break;
			}
		}
		cout << ans << '\n';
	}
}