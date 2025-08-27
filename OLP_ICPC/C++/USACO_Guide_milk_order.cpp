#include <iostream>
#include <vector>
using namespace std;

int n, m, k;

/**
 * @return whether it's possible to construct a valid ordering with given fixed elements
 */
bool check(vector<int> order, vector<int> &hierarchy) {
	vector<int> cow_to_pos(n, -1);
	for (int i = 0; i < n; ++i)
		if (order[i] != -1) cow_to_pos[order[i]] = i;
	int h_idx = 0;
	for (int i = 0; i < n && h_idx < m; ++i)
		if (cow_to_pos[hierarchy[h_idx]] != -1) {
			// we know the next cow has to be in front of it
			if (i > cow_to_pos[hierarchy[h_idx]]) return false;
			i = cow_to_pos[hierarchy[h_idx]];
			++h_idx;
		}
		else {
			while (i < n && order[i] != -1) ++i;
			if (i == n) return false; // run out of places
			order[i] = hierarchy[h_idx];
			cow_to_pos[hierarchy[h_idx]] = i;
			++h_idx;
		}
	return true;
}

int main() {
	cin >> n >> m >> k;
	vector<int> hierarchy(m);
	for (int i = 0; i < m; ++i) {
		cin >> hierarchy[i];
		--hierarchy[i];
	}
	vector<int> order(n, -1);
	for (int i = 0; i < k; ++i) {
		int cow, pos;
		cin >> cow >> pos;
		order[--pos] = --cow;
		if (cow == 0) { // already fixed, nothing we can do
			cout << pos + 1 << '\n';
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (order[i] == -1) { // if already fixed, skip
			order[i] = 0; // try placing cow 1 at position i
			if (check(order, hierarchy)) {
				cout << i + 1 << '\n';
				break;
			}
			order[i] = -1;
		}
	}
}