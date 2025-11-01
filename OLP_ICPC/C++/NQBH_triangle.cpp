#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	vector<int> a(4);
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());
	bool triangle = false;
	for (int i = 0; i < 2; ++i)
		if (a[i] + a[i + 1] > a[i + 2]) {
			triangle = true;
			break;
		}
	if (triangle) {
		cout << "TRIANGLE";
		return 0;
	}
	if (a[0] + a[1] == a[2] || a[0] + a[1] == a[3] || a[0] + a[2] == a[3] || a[1] + a[2] == a[3]) {
		cout << "SEGMENT";
		return 0;
	}
	cout << "IMPOSSIBLE";
}