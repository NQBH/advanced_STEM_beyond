#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	ll ans = n * k; // total unit block passed, not subtract common unit blocks yet
	ll triple_common = 0; // count the number of redundant counts of common unit blocks of 3 different drills
	vector<vector<ll>> a(k, vector<ll>(3));
	set<tuple<ll, ll, ll>> common_unit_blocks; // set of common unit blocks drilled with 3 coordinates
	vector<int> pos_zero(k); // pos_zero[i] = position where 0 is in row i
	for (ll i = 0; i < k; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][0] == 0) pos_zero[i] = 0;
		else if (a[i][1] == 0) pos_zero[i] = 1;
		else pos_zero[i] = 2;
	}
	for (ll i = 0; i < k; ++i) // row i
		for (ll j = i + 1; j < k; ++j) // row j
			if (pos_zero[i] != pos_zero[j]) { // if pos_zero[i] = pos_zero[j], then 2 potential unit blocks are on same face cannot have common drilled unit block
				int nonzero_pos = 3 - pos_zero[i] - pos_zero[j];
				if (a[i][nonzero_pos] == a[j][nonzero_pos]) { // 2 potential unit blocks whose 2 drills have exactly 1 common drilled unit block
					tuple<ll, ll, ll> common_unit_block;
					if (nonzero_pos == 0) common_unit_block = make_tuple(a[i][0], a[i][1] ? a[i][1] : a[j][1], a[i][2] ? a[i][2] : a[j][2]);
					else if (nonzero_pos == 1) common_unit_block = make_tuple(a[i][0] ? a[i][0] : a[j][0], a[i][1], a[i][2] ? a[i][2] : a[j][2]);
					else common_unit_block = make_tuple(a[i][0] ? a[i][0] : a[j][0], a[i][1] ? a[i][1] : a[j][1], a[i][2]);
					if (!common_unit_blocks.count(common_unit_block)) common_unit_blocks.insert(common_unit_block);
					else ++triple_common;
				}
			}
	cout << ans - triple_common - common_unit_blocks.size() + triple_common / 2;
}