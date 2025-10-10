#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < n; ++i) {
			cin >> m;
			if (m == 1) {
				count1++;
			}
			else count2++;
		}
		int sum = (count1 + 2 * count2);
		if (sum % 2 != 0) {
			cout << "no" << endl; continue;
		}
		int half = sum / 2;
		if (half % 2 == 0 or (half % 2 == 1 and count1 != 0)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
