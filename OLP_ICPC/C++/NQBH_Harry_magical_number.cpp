#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> ans;
	for (int i = 2; i * i <= c; ++i) {
		if (c % i == 0 && i % a == 0 && i % b != 0 && d % i != 0) {
			cout << i;
			return 0;
		}
		int tmp = c / i;
		if (c % tmp == 0 && tmp % a == 0 && tmp % b != 0 && d % tmp != 0) ans.push_back(tmp);
	}
	if (!ans.empty()) cout << ans.back();
	else cout << -1;
}