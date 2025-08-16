#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, sum = 0, ans;
	cin >> n;
	int l = 2 * n;
	int w[l];
	for (int i = 0; i < l; ++i) cin >> w[i];
	sort(w, w + l);
	for (int i = 3; i < l; i += 2) sum += w[i] - w[i - 1] ; // case w[0], w[1] are on single kayak
	ans = sum; // init answer
	sum = 0;
	for (int i = 1; i < l - 2; i += 2) sum += w[i] - w[i - 1] ; // case w[l - 2], w[l - 1] are on single kayak
	ans = min(ans, sum);
	sum = 0;
	for (int i = 2; i < l - 1; i += 2) sum += w[i] - w[i - 1] ; // case w[0], w[l - 1] are on single kayak
	ans = min(ans, sum);
	cout << ans;
}

// 3 
// 610 750 778 6 361 407
