#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		vector<int> dp11(n + 1), dp12(n + 1), dp21(n + 1), dp22(n + 1);
		dp11[1] = 0;
		dp12[1] = 0;
		dp21[1] = (a[1] == 1 ? 1 : 0);
		dp22[1] = 0;
		dp11[2] = dp21[1];
		dp12[2] = 0;
		dp21[2] = dp11[1] + (a[2] == 1 ? 1 : 0);
		dp22[2] = (a[0] == 1 ? 1 : 0) + (a[1] == 1 ? 1 : 0);
		for (int i = 3; i <= n; ++i) {
			dp11[i] = dp21[i - 1] + dp22[i - 2];
			dp12[i] = dp21[i - 2] + dp22[i - 2];
			dp21[i] = dp11[i - 1] + dp12[i - 1] + (a[i] == 1 ? 1 : 0);
			dp22[i] = dp11[i - 2] + dp12[i - 2] + (a[i] == 1 ? 1 : 0) + (a[i - 1] == 1 ? 1 : 0);
		}
		int ans;
		ans = min({dp11[n], dp12[n], dp21[n], dp22[n]});
		cout << ans << '\n';
	}
}