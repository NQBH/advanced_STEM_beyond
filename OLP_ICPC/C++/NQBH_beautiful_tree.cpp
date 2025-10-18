#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 2) cout << "-1\n";
		else if (n == 3) cout << "1 3\n2 3\n";
		else if (n == 4) cout << "1 2\n1 3\n1 4\n";
		else {
			cout << "1 2\n2 3\n3 4\n1 " << n << '\n';
			for (int i = 5; i < n; ++i) cout << "2 " << i << '\n';
		}
	}
}