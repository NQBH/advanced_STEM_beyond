#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> current_subset;

void print_subset() {
	for (int i : current_subset) cout << i << " ";
	cout << '\n';
}

void generate_subset(int pos) {
	int last_num = (current_subset.empty() ? 0 : current_subset.back()); // last chosen number
	for (int i = last_num + 1; i <= n; ++i) {
		current_subset.push_back(i);
		if (current_subset.size() == k) print_subset();
		else generate_subset(pos + 1);
		current_subset.pop_back();
	}
}

int main() {
	cin >> n >> k;
	current_subset.clear();
	generate_subset(1);
}