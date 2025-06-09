#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--) {
		int A, B;
		cin >> A >> B;
		if ((2 * A - B) % 3 || (2 * A - B) < 0 || (2 * B - A) % 3 || (2 * B - A) < 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}