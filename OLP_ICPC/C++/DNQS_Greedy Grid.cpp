#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;

    // NO nếu n=1, m=1, hoặc n=2 và m=2. Ngược lại là YES.
    if (n == 1 || m == 1 || (n == 2 && m == 2)) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}