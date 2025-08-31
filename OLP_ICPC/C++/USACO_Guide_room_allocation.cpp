#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> ans(n);
	vector<pair<pair<int, int>, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i; // store the original index
	}
	sort(v.begin(), v.end());
	int last_room = 0;
	using room = pair<int, int>;
	priority_queue<room, vector<room>, greater<room>> pq;
	for (int i = 0; i < n; ++i)
		if (pq.empty() || pq.top().first >= v[i].first.first) {
			++last_room;
			pq.push(make_pair(v[i].first.second, last_room));
			ans[v[i].second] = last_room;
		} else { // accessing the minimum departure time
			room minimum = pq.top();
			pq.pop();
			pq.push(make_pair(v[i].first.second, minimum.second));
			ans[v[i].second] = minimum.second;
		}
	cout << last_room << '\n';
	for (int i = 0; i < n; ++i) cout << ans[i] << " ";
}