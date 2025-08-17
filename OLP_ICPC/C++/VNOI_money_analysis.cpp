#include <iostream>
#include <vector>
using namespace std;

int n, a[15];
long long S, curr_money_sum;
vector<int> curr_money_set;

void print_money_set() {
	for (auto i : curr_money_set) cout << a[i] << " ";
	cout << '\n';
}

void get_money_set(int pos) { // backtracking
	int last_index = (curr_money_set.empty() ? 1 : curr_money_set.back());
	for (int i = last_index; i <= n; ++i) {
		// add a new money into set
		curr_money_set.push_back(i);
		curr_money_sum += a[i];

		// call recursion
		if (curr_money_sum >= S) {
			if (curr_money_sum == S) print_money_set();
		}
		else get_money_set(pos + 1);
		// remove this new money out of set
		curr_money_set.pop_back();
		curr_money_sum -= a[i];
	}
}

int main() {
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	curr_money_set.clear();
	curr_money_sum = 0;
	get_money_set(1);
}