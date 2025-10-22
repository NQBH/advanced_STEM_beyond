#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	// find a[1], a[2], a[3]
	ll x, y, S1, S2, S3;
	cout << "and 1 2" << endl;
	cin >> x;
	cout << "or 1 2" << endl;
	cin >> y;
	S1 = x + y;
	cout << "and 2 3" << endl;
	cin >> x;
	cout << "or 2 3" << endl;
	cin >> y;
	S2 = x + y;
	cout << "and 1 3" << endl;
	cin >> x;
	cout << "or 1 3" << endl;
	cin >> y;
	S3 = x + y;
	vector<ll> a(n + 1, -1);
	ll S = (S1 + S2 + S3) / 2;
	a[1] = S - S2;
	a[2] = S - S3;
	a[3] = S - S1;
	// compute a[4..n]
	for (int i = 4; i <= n; ++i) {
		cout << "and 1 " << i << endl;
		cin >> x;
		cout << "or 1 " << i << endl;
		cin >> y;
		a[i] = x + y - a[1];
	}
	sort(a.begin(), a.end());
	cout << "finish " << a[k] << endl;
}