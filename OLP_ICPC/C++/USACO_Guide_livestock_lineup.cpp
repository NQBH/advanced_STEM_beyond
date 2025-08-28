#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Lambda expression
const vector<string> COWS = []() {
	vector<string> tmp{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	sort(begin(tmp), end(tmp)); // sort names lexicographically
	return tmp;
}();

int main() {
	map<string, int> cow_idxs;
	for (int i = 0; i < COWS.size(); ++i) cow_idxs[COWS[i]] = i;
	int req_num;
	cin >> req_num;
	vector<vector<int>> neighbors(COWS.size());
	for (int r = 0; r < req_num; ++r) {
		string cow1, cow2, trash;
		cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;
		// convert the names to their index in the list
		int c1 = cow_idxs[cow1], c2 = cow_idxs[cow2];
		neighbors[c1].push_back(c2);
		neighbors[c2].push_back(c1);
	}
	vector<int> order;
	vector<bool> added(COWS.size());
	for (int c = 0; c < COWS.size(); ++c)
		if (!added[c] && neighbors[c].size() <= 1) {
			added[c] = true;
			order.push_back(c);
			if (neighbors[c].size() == 1) {
				int prev = c, at = neighbors[c][0];
				while (neighbors[at].size() == 2) {
					added[at] = true;
					order.push_back(at);
					int a = neighbors[at][0], b = neighbors[at][1];
					int temp_at = a == prev ? b : a;
					prev = at;
					at = temp_at;
				}
				added[at] = true;
				order.push_back(at);
			}
		}
	for (int c : order) cout << COWS[c] << '\n';
}