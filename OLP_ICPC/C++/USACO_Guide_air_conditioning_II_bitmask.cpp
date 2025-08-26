#include <array>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

/** @return if the given AC units satisfy the constraints of the cows */
bool check(vector<array<int, 3>> &cows, vector<array<int, 4>> &air_conditioners) {
	// iterate through all positions to check if the current subset is feasible
	for (int i = 1; i <= 100; ++i) {
		int cooling = 0;
		for (int j = 0; j < air_conditioners.size(); ++j) {
			auto &[a, b, p, m] = air_conditioners[j];
			if (a <= i && i <= b) cooling += p;
		}
		//  iterate through cows to find the current cow
		int cow_requirement = 0;
		for (int j = 0; j < cows.size(); ++j) {
			auto &[s, t, c] = cows[j];
			if (s <= i && i <= t) {
				cow_requirement = c;
				break;
			}
		}
		// for each position, the requirement of the cow must be met
		if (cooling < cow_requirement) return false;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> cows;
	for (int i = 0; i < n; ++i) {
		int s, t, c;
		cin >> s >> t >> c;
		cows.push_back({s, t, c});
	}
	vector<array<int, 4>> air_conditioners;
	for (int i = 0; i < m; ++i) {
		int a, b, p, m;
		cin >> a >> b >> p >> m;
		air_conditioners.push_back({a, b, p, m});
	}
	int min_cost = numeric_limits<int>().max();
	for (int mask = 0; mask < (1 << m); ++mask) { // use a bit mask to get all subsets
		int cost = 0;
		vector<array<int, 4>> used_conditioners;
		for (int i = 0; i < m; ++i)
			if (mask & (1 << i)) {
				used_conditioners.push_back(air_conditioners[i]);
				cost += air_conditioners[i][3];
			}
		if (check(cows, used_conditioners)) min_cost = min(min_cost, cost);
	}
	cout << min_cost << '\n';
}