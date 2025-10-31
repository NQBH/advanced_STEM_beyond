#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int num1 = 0;
		for (int &x : a) {
			cin >> x;
			if (x == 1) ++num1;
		}
		if (num1 > k) {
			cout << "1\n";
			continue;
		}
		if (n == 1 && k == 0) {
			cout << a[0] << '\n';
			continue;
		}


	}
}