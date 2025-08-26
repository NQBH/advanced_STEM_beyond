#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<pair<int, int>> cowlocs;
vector<int> comfort;
vector<pair<int, int>> conditioners;
vector<int> cost, power;
int ans = 1e9;

int check(string subset) {
	vector<int> cold(101); // generate coldness of all points
	for (int i = 1; i <= 100; ++i)
		for (int j = 0; j < conditioners.size(); ++j)
			if (subset[j] == '1' && conditioners[j].first <= i && conditioners[j].second >= i) cold[i] += power[j];
	bool works = true;
	for (int i = 0; i < cowlocs.size(); ++i)
		for (int j = cowlocs[i].first; j <= cowlocs[i].second; ++j)
			if (cold[j] < comfort[i]) works = false; // check if comfortable
	int price = 0;
	for (int i = 0; i < subset.size(); ++i)
		if (subset[i] == '1') price += cost[i]; // calculate price of conditioners used
	if (works) return price;
	return 1e9; // does not work,
}

void build_subset(string curr, int m) {
	if (curr.size() == m) ans = min(ans, check(curr)); // full subset of conditioners
	else {
		build_subset(curr + "1", m); // use conditioner
		build_subset(curr + "0", m); // skip it
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int s, t, c;
		cin >> s >> t >> c;
		cowlocs.push_back({s, t});
		comfort.push_back(c);
	}
	for (int i = 0; i < m; ++i) {
		int a, b, p, c;
		cin >> a >> b >> p >> c;
		conditioners.push_back({a, b});
		power.push_back(p);
		cost.push_back(c);
	}
	build_subset("", m);
	cout << ans << '\n';
}