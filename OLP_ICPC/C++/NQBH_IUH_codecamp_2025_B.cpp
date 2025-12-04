#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, w, h, ans = 0;
	cin >> n;
	stack<int> S;
	for (int i = 0; i < n; ++i) {
		cin >> w >> h;
		while (!S.empty() && S.top() > h) S.pop(); // higher to lower: cannot use h anymore		
		if (S.empty() || S.top() < h) { // need a new higher poster
			++ans;
			S.push(h);
		}
	}
	cout << ans;
}