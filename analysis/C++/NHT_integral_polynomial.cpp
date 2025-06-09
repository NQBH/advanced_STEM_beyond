#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int n, a, b;
ld p[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> a >> b;
	for (int i = n; i >= 0; --i)
		cin >> p[i];
	ld ans = 0;
	for (int i = n; i >= 0; --i)
		ans += ((p[i] / (i + 1)) * (pow(b, i + 1) - pow(a, i + 1)));
	cout << fixed << setprecision(10) << ans << '\n';
	for (int i = n; i >= 0; --i)
		cout << fixed << setprecision(10) << p[i] / (i + 1) << '*' << "x^"
		     << i + 1 << " + ";
	cout << "C";
	return 0;
}