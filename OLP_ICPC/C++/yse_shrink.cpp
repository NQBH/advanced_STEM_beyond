#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) cout << i << ' ';
    cout << "1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}