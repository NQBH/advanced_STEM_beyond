#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) cout << 2 << '\n';
		else {
			int num_win_team = n, num_lose_team = 0, num_move_team, ans = 0;
			while (num_win_team + num_lose_team > 2) {
				num_move_team = num_win_team / 2;
				ans += num_move_team + num_lose_team / 2;
				num_win_team -= num_move_team;
				num_lose_team -= (num_lose_team / 2);
				num_lose_team += num_move_team;
			}
			++ans;
			cout << ans << '\n';
		}
	}
}