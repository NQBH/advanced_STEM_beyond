#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct edge {
	char name[100];
	int sol, total;
	bool operator<(const edge &other) const {
		return sol < other.sol || (sol == other.sol && total > other.total);
	}
} teams;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	priority_queue<edge> pq;
	for (int i = 0; i < n; ++i) {
		cin >> teams.name;
		teams.sol = 0;
		teams.total = 0;

		for (int j = 0; j < 4; ++j) {
			int a, b;
			cin >> a >> b;

			if (b) {
				++teams.sol;
				teams.total += ((a - 1) * 20 + b);
			}
			pq.push(teams);
		}
	}
	edge t = pq.top();
	cout << t.name << " " << t.sol << " " << t.total << endl;
	return 0;
}