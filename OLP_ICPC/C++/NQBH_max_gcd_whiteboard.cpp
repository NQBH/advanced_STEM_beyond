#include <algorithm>
#include <iostream>
#include <unordered_map>
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
		unordered_map<int, int> freq; // frequency
		// set<int> A;
		int num1 = 0;
		for (int &x : a) {
			cin >> x;
			++freq[x];
			if (x == 1) ++num1;
			// A.insert(x);
		}
		if (num1 > k) { // cannot erase all 1s
			cout << 1 << '\n';
			continue;
		}
		// find all divisors of a[i]
		/*
		vector<int> divisor;
		for (int x : A)
			for (int d = 2; d <= x; ++d)
				if (x % d == 0 && !count(divisor.begin(), divisor.end(), d))
					divisor.push_back(d);
		
		sort(divisor.begin(), divisor.end(), [](int a, int b) {
			return a >= b; // Return true if 'a' should come before 'b' (for descending order)
		});
		*/
		// for (int &x : divisor) cout << x << ' ';
		int ans = 1; // worst case
		int a_max = *max_element(a.begin(), a.end());
		for (int d = 2; d <= a_max; ++d) { // check if d can be beauty or not
			int num_erase = 0;
			for (auto [x, f] : freq)
				if (x % d != 0 && x < 4 * d) num_erase += f; // x must be >= 4d to apply Split
			if (num_erase <= k) {
				ans = d;
			}
		}
		cout << ans << '\n';
	}
}