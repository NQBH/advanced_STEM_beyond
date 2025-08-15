#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, ans = 1;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());
	for (int i = 1; i < n; ++i) if (a[i] != a[i - 1]) ++ans;
	cout << ans;
}