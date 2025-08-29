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
	for (int i = 0; i < bale_num; ++i) cin >> bales[i];
	sort(begin(bales), end(bales));
	for (int i = 0; i < query_num; ++i) {
		int q_start, q_end;
		cin >> q_start >> q_end;
		cout << upper_bound(begin(bales), end(bales), q_end) - lower_bound(begin(bales), end(bales), q_start) << '\n';
	}
}