#include <bits/stdc++.h>
 
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << std::max(n, m) + 1 << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    int t = 1;
    std::cin >> t;    
    while (t--) solve();
}