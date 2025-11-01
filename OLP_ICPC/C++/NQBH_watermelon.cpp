#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int w;
	cin >> w;
	if ((w & 1) == 0 && w > 2) cout << "YES\n";
	else cout << "NO\n";
}