#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << "1 ";
		for (int i = 3; i <= n; ++i) cout << i << ' ';
		cout << "2\n";
	}
}