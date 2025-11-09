#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n & 1) cout << "9 " << n - 9 << '\n';
	else cout << "8 " << n - 8 << '\n';
}