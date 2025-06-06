#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, X;
int a[100], b[100];
ll res;
vector<ll> cntA, cntB;

void backtrackA(int i, ll sum) {
	if (i == n + 1) {
		cntA.push_back(sum);
		return;
	}
	backtrackA(i + 1, sum + a[i]);
	backtrackA(i + 1, sum);
}

void backtrackB(int i, ll sum) {
	if (i == m + 1) {
		cntB.push_back(sum);
		return;
	}
	backtrackB(i + 1, sum + b[i]);
	backtrackB(i + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> X;
	m = n - n / 2;
	n /= 2;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];

	backtrackA(1, 0);
	backtrackB(1, 0);

	sort(cntA.begin(), cntA.end(), greater<ll>());
	sort(cntB.begin(), cntB.end());

	for (int i = 0, j1 = 0, j2 = 0; i < cntA.size(); ++i) {
		while (j1 < cntB.size() && cntB[j1] < X - cntA[i])
			j1++;
		while (j2 < cntB.size() && cntB[j2] <= X - cntA[i])
			j2++;
		res += j2 - j1;
	}

	cout << res << endl;

	return 0;
}