/*
Source: ACM Mid-Central United States 2003.
IDs for online judges: POJ 1552, ZOJ 1760, UVA 2787.
Status: Accepted
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {	
	map<int, int> ma;
	vector<int> a;
	int n, ans = 0;
	while (cin >> n) {
		if (n == -1) {
			break;
		}
		if (n == 0) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] % 2 == 1) continue;
				ans += ma[a[i] / 2];
			}
			cout << ans << endl;
			ans = 0;
			ma.clear();
			a.clear();
			continue;
		}
		a.push_back(n);
		ma[n]++;
	}
}