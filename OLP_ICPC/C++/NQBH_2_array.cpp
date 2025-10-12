#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, c, d, mina = 2e9, maxa = -2e9, minb = 2e9, maxb = -2e9, idx_mina = 0, idx_maxa = 0, idx_minb = 0, idx_maxb = 0;
		cin >> n >> c >> d;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {			
			cin >> a[i];
			if (a[i] < mina) {
				mina = a[i];
				idx_mina = i;
			}
			if (a[i] > maxa) {
				
			}
		}

		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}


	}
}