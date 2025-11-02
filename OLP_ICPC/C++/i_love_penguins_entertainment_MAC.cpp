#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
    	int n;
    	std::cin >> n;
        std::string s;
        std::cin >> s;
        std::string t = s;
        reverse(t.begin(), t.end());
        std::cout << std::min(s, t + s) << "\n";
    }
}