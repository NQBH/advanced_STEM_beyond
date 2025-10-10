#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int A = B = 0; // total points of Alice & Bob
		vector<int> a(n);
		for (int& v : a) cin >> v;
		sort(a.begin(), a.end());
		if (a[n - 1] % 2 == 0) {
			A += a[n - 1];
		}


			cout << "Alice\n";

	}
}