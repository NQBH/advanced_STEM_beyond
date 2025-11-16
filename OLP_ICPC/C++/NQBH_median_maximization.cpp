#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		cout << s / (n / 2 + 1) << '\n';
	}
}