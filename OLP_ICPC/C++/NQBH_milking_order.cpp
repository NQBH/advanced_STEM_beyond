#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> order(m + 1), turn_of_cow(n + 1, 0), cow_at_pos(n + 1, 0); // turn_of_cow[i]: the time when ith cow gets milked
	for (int i = 1; i <= m; ++i) cin >> order[i];
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			cout << b;
			return 0;
		}
		turn_of_cow[a] = b;
		cow_at_pos[b] = a;
	}
	
	int pos = 0, idx_cow_order = 0;
	for (int i = m; i >= 1; --i) // find the last cow in social order with already known milking order
		if (turn_of_cow[order[i]]) {
			idx_cow_order = i;
			pos = turn_of_cow[order[i]] - 1;
			break;
		}
	for (int i = idx_cow_order - 1; i >= 1; ++i) { // find milking turn for all next social order cows
		if (turn_of_cow[order[i]])  {
			pos = turn_of_cow[order[i]] - 1;
			continue;
		}
		else {
			while (turn_of_cow[pos]) --pos;
			turn_of_cow[order[i]] = pos;
		}
	}
	// DEBUG
	for (int i = 1; i <= n; ++i) cout << turn_of_cow[i] << " ";
	cout << '\n';
	for (int i = 1; i <= n; ++i) cout << cow_at_pos[i] << " ";
	cout << '\n';
	cout << pos << '\n';
	/*
	if (turn_of_cow[order[m]]) { // already know the milking turn of the order[m]th cow
		int pos = turn_of_cow[order[m]] - 1;
		for (int i = m - 1; i >= 1; --i) {
			if (turn_of_cow[order[i]]) {
				pos = turn_of_cow[order[i]] - 1;
				continue;
			}
			else { // if the order[i]th cow does not have milking turn yet
				while (cow_at_pos[pos]) --pos;
				turn_of_cow[order[i]] = pos;
				cow_at_pos[pos] = order[i];
			}
		}
	}
	else {
		for (int i = 1; i <= m; ++i) {
			if (i < m && !turn_of_cow[order[i]] && turn_of_cow[order[i + 1]]) {
				// milk the order[i]th cow as early as possible before turn_of_cow[order[i + 1]]
				int pos = turn_of_cow[order[i + 1]] - 1;
				while (cow_at_pos[pos]) --pos;
				turn_of_cow[order[i]] = pos;
				cow_at_pos[pos] = order[i];
			}
		}
	}
	*/
	for (int i = 1; i <= n; ++i)
		if (!cow_at_pos[i]) {
			cout << i << '\n';
			return 0;
		}
}