#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q, a, b;
	cin >> n >> q;
	vector<int> cow_id(n + 1), prefix_sum_1(n + 1, 0), prefix_sum_2(n + 1, 0), prefix_sum_3(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> cow_id[i];
	for (int i = 1; i <= n; ++i) {
		prefix_sum_1[i] = prefix_sum_1[i - 1] + (cow_id[i] == 1);
		prefix_sum_2[i] = prefix_sum_2[i - 1] + (cow_id[i] == 2);
		prefix_sum_3[i] = prefix_sum_3[i - 1] + (cow_id[i] == 3);
	}
	while (q--) {
		cin >> a >> b;
		cout << prefix_sum_1[b] - prefix_sum_1[a - 1] << " " << prefix_sum_2[b] - prefix_sum_2[a - 1] << " "
			 << prefix_sum_3[b] - prefix_sum_3[a - 1] << '\n';
	}
}