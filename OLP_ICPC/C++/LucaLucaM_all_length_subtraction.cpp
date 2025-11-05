#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using ll = long long;

#define debug(x) #x << " = " << x << '\n'
#define YES std::cout << "YES" << std::endl;
#define NO std::cout << "NO" << std::endl;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for (int i = 0; i < n; i++) std::cin >> p[i];
	int l = 0, r = n - 1;
	for (int i = 1; i <= n; ++i)
		if (p[l] == i) ++l;
		else if (p[r] == i) --r;
		else {
			NO;
			return;
		}
	YES;
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	for (int tc = 1; tc <= t; tc++) solve();
}