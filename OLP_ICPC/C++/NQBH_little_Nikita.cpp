#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << (n >= m && (n - m) % 2 == 0 ? "Yes\n" : "No\n");		
	}
}