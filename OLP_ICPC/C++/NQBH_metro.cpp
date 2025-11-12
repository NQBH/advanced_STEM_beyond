#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s;
	cin >> n >> s;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	if (a[0] == 0) cout << "NO";
	else if (a[s - 1] == 1) cout << "YES"; // direct
	else if (b[s - 1] == 0) cout << "NO";
	else {
		bool ok = false;
		for (int i = s; i < n; ++i)
			if (a[i] == 1 && b[i] == 1) { // get off, take 2nd track
				ok = true;
				break;
			}
		cout << (ok ? "YES" : "NO");
	}	
}