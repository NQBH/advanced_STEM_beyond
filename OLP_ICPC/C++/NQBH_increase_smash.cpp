#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		set<int> a;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			a.insert(x);
		}
		cout << a.size() * 2 - 1 << '\n';
	}
}