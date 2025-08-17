#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a, current_arrangement, current_combination;

void print_arrangement() {
	for (int i : current_arrangement) cout << i << " ";
	cout << '\n';
}

void generate_arrangement(int pos) {
	if (current_arrangement.empty())
		for (int i = 0; i < n; ++i) {
			current_arrangement.push_back(a[i]);
			generate_arrangement(pos);
			current_arrangement.pop_back();
		}

	bool flag = true;
	for (int i = 0; i < n; ++i) {
		for (size_t j = 0; j < current_arrangement.size(); ++j)
			if (current_arrangement[j] == a[i]) {
				flag = false; // cannot add a[i] into current arrangement due to duplication
				break;
			}
		if (flag == false) continue;
		else { // can add a[i] into current arrangement
			current_arrangement.push_back(a[i]);
			if (current_arrangement.size() == k) print_arrangement();
			else generate_arrangement(pos + 1);
			current_arrangement.pop_back();
		}
	}
}

void print_combination() {
	for (int i : current_combination) cout << i << " ";
	cout << '\n';
}

void generate_combination(int pos) {
	if (current_combination.empty())
		for (int i = 0; i < n; ++i) {
			current_combination.push_back(a[i]);
			generate_combination(pos);
			current_combination.pop_back();
		}

	int last_num = current_combination.back(); // last chosen number
	int start_idx = n - 1;
	for (int i = 0; i < n; ++i) { // find the 1st index i s.t. a[i] > last_num
		if (a[i] == last_num) {
			start_idx = i;
			break;
		}
	}
	for (int i = start_idx + 1; i < n; ++i) {
		current_combination.push_back(a[i]);
		if (current_combination.size() == k) print_combination();
		else generate_combination(pos + 1);
		current_combination.pop_back();
	}
}

int main() {
	cin >> n >> k;
	a.resize(n);
	for (int& v : a) cin >> v; // distinct elements
	sort(a.begin(), a.end());
	current_combination.clear();
	generate_combination(1);
	cout << '\n';
	current_arrangement.clear();
	generate_arrangement(1);
	cout << '\n';
	k = n;
	current_arrangement.clear();
	generate_arrangement(1);
}