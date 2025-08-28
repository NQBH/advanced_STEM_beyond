#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> cow_id(n + 1);
	vector<vector<int>> prefix_cow_id(4, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i) cin >> cow_id[i];
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= n; ++j)
			prefix_cow_id[i][j] = prefix_cow_id[i][j - 1] + (cow_id[j] == i);
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << prefix_cow_id[1][b] - prefix_cow_id[1][a - 1]
			 << " " << prefix_cow_id[2][b] - prefix_cow_id[2][a - 1]
		     << " " << prefix_cow_id[3][b] - prefix_cow_id[3][a - 1] << '\n';
	}
}