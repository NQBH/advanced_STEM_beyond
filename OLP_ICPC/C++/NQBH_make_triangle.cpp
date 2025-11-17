#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 2 * max({a, b, c}) - a - b - c;
	cout << (ans < 0 ? 0 : ans + 1);
}