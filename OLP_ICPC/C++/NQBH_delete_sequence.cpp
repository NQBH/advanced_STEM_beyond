#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

bool operation1_ok(int a, int b) {
	if (gcd(a, b) == 1 || a % b == 0 || b % a == 0) return true;
	else return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		while (!a.empty()) {
			if (a.size() == 1) { // add x to become (2x, x)
				++++ans;
				break;
			} 
			if (operation1_ok(a[0], a[1])) { // do operation 1 
				a.erase(a.begin());
				a.erase(a.begin());
				++ans;			
			} else { // do operation 2
				if (a.size() % 2 == 0) {
					if (a[0] > a[1]) {
						for (int i = 2; i <= a[1] - (a[0] % a[1]); ++i)
							if (operation1_ok(a[0] + i, a[1])) {
								a[0] += i;
								a.push_back(i);
								++ans;
								break;
							}
					} else { // a[0] < a[1]
						for (int i = 2; i <= a[1] - a[0]; ++i) {
							if (operation1_ok(a[0] + i, a[1])) {
								a[0] += i;
								a.push_back(i);
								++ans;
								break;
							}
						}
					}
				} else { // a.size() % 2 == 1
					int c = a.back();
					if (a[0] > a[1]) {
						for (int i = 2; i <= max(a[1] - (a[0] % a[1]), c); ++i)
							if (operation1_ok(a[0] + i, a[1]) && operation1_ok(c, i)) {
								a[0] += i;
								a.push_back(i);
								++ans;
								break;
							}
					} else { // a[0] < a[1]
						for (int i = 2; i <= max(a[1] - a[0], c); ++i) {
							if (operation1_ok(a[0] + i, a[1]) && operation1_ok(c, i)) {
								a[0] += i;
								a.push_back(i);
								++ans;
								break;
							}
						}
					}
				}

			}
		}
		cout << ans << '\n';
	}
}