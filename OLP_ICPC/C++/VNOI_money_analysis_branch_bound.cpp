#include <iostream>
#include <vector>
using namespace std;

int n, a[15];
long long S, curr_money_sum;
vector<int> curr_money_set, best_set;

void get_money_set(int pos) {
	int last_index = (curr_money_set.empty() ? 1 : curr_money_set.back());
	for (int i = last_index; i <= n; ++i) {
		curr_money_set.push_back(i);
		curr_money_sum += a[i];
		if (curr_money_sum >= S) {
			if (curr_money_sum == S) {
				best_set.clear();
				for (int i : curr_money_set) best_set.push_back(i);
			}
		}
		else if (best_set.empty() || curr_money_set.size() < best_set.size()) get_money_set(pos + 1); // loại ngay nếu không tối ưu
		curr_money_set.pop_back();
		curr_money_sum -= a[i];
	}
}

int main() {
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	curr_money_set.clear();
	curr_money_sum = 0;
	best_set.clear();
	get_money_set(1);
	for (int i : best_set) cout << a[i] << " ";
}