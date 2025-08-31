#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> events(n);
	for (int i = 0; i < n; ++i) cin >> events[i].second >> events[i].first;
	sort(events.begin(), events.end()); // sort by 1st element (ending time)
	int ans = 0, current_event_end = -1; // end of event currently attending
	for (int i = 0; i < n; ++i) // process events in order of end time
		if (events[i].second >= current_event_end) { // if event can be attended, we know that this is the earliest ending event that we can attend becaues of how the events are sorted
			current_event_end = events[i].first;
			++ans;
		}
	cout << ans << '\n';
}