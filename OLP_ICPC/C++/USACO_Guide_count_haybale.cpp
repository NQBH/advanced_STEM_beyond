#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); // // alternatively, cin.tie(0)->sync_with_stdio(0);
	int bale_num, query_num;
	cin >> bale_num >> query_num;
	vector<int> bales(bale_num);
	for (int &i : bales) cin >> i;
	sort(begin(bales), end(bales));
	// return the number of elements that are at most x
	auto at_most = [&](int x) {
		int lo = 0, hi = bales.size();
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (bales[mid] <= x) lo = mid + 1;
			else hi = mid;
		}
		return lo;
	};
	for (int i = 0; i < query_num; ++i) {
		int q_start, q_end;
		cin >> q_start >> q_end;
		cout << at_most(q_end) - at_most(q_start - 1) << '\n';
	}
}