#include <iostream>
using namespace std;

bool used_cow[100], used_pos[100];
int pos[100], n_cows, m, n_fixed, ord[100], c_fixed[101], p_fixed[101];

bool works() {
	for (int i = 0; i < n_cows; ++i) used_cow[i] = used_pos[i] = 0;
	for (int i = 0; i < n_fixed; ++i) {
		if (used_cow[c_fixed[i]] && pos[c_fixed[i]] == p_fixed[i]) continue;
		if (used_cow[c_fixed[i]]) return 0;
		if (used_pos[p_fixed[i]]) return 0;
		used_cow[c_fixed[i]] = 1;
		used_pos[p_fixed[i]] = 1;
		pos[c_fixed[i]] = p_fixed[i];
	}
	int j = 0;
	for (int i = 0; i < m; ++i) {
		int cow = ord[i];
		if (used_cow[cow]) {
			if (j > pos[cow]) return 0;
			j = pos[cow];
			continue;
		}
		while (used_pos[j]) {
			++j;
			if (j == n_cows) return 0;
		}
		used_pos[j] = 1;
		pos[cow] = j;
	}
	return 1;
}

int main() {
	cin >> n_cows >> m >> n_fixed;
	for (int i = 0; i < m; ++i) {
		cin >> ord[i];
		--ord[i];
	}
	for (int i = 0; i < n_fixed; ++i) {
		cin >> c_fixed[i] >> p_fixed[i];
		--c_fixed[i], --p_fixed[i];
	}
	++n_fixed;
	for (int i = 0; i < n_cows; ++i) {
		c_fixed[n_fixed - 1] = 0;
		p_fixed[n_fixed - 1] = i;
		if (works()) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
}