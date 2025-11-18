#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n & 1) cout << 0;
	else cout << n / 4 - (n % 4 == 0);
}