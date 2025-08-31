#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> Point;
bool ycomp(Point p, Point q) { return p.second < q.second; }
const int MAX_N = 2500;
int pref[MAX_N + 1][MAX_N + 1];
Point p[MAX_N];

int rsum(int x1, int y1, int x2, int y2) {
	return pref[x2 + 1][y2 + 1] - pref[x2 + 1][y1] - pref[x1][y2 + 1] + pref[x1][y1];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}
	sort(p, p + n);
	for (int i = 0; i < n; ++i) p[i].first = i + 1;
	sort(p, p + n, ycomp);
	for (int i = 0; i < n; ++i) p[i].second = i + 1;
	for (int i = 0; i < n; ++i) pref[p[i].first][p[i].second] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			int x1 = min(p[i].first, p[j].first) - 1, x2 = max(p[i].first, p[j].first) - 1;
			ans += rsum(0, i, x1, j) * rsum(x2, i, n - 1, j);
		}
	cout << ans + 1 << '\n';
}