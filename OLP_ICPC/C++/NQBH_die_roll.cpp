#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int y, w;
	cin >> y >> w;
	int d = 6 - max(y, w) + 1;
	if (d == 1 || d == 5) cout << d << '/' << 6;
	else if (d == 2) cout << "1/3";
	else if (d == 3) cout << "1/2";
	else if (d == 4) cout << "2/3";
	else cout << "1/1";
}