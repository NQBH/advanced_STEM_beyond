#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> current_arrangement, current_combination;

void print_arrangement() {
	for (int i : current_arrangement) cout << i << " ";
	cout << '\n';
}

void generate_arrangement(int pos) {
	if (current_arrangement.empty())
		for (int i = 1; i <= n; ++i) {
			current_arrangement.push_back(i);
			generate_arrangement(pos);
			current_arrangement.pop_back();
		}

	bool flag = true;
	for (int i = 1; i <= n; ++i) {
		for (size_t j = 0; j < current_arrangement.size(); ++j) {
			if (current_arrangement[j] == i) flag = false; // cannot add i into current arrangement due to duplication
			break;
		}
		if (flag == false) continue;
		else { // can add i into current arrangement
			current_arrangement.push_back(i);
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
	int last_num = (current_combination.empty() ? 0 : current_combination.back()); // last chosen number
	for (int i = last_num + 1; i <= n; ++i) {
		current_combination.push_back(i);
		if (current_combination.size() == k) print_combination();
		else generate_combination(pos + 1);
		current_combination.pop_back();
	}
}

int main() {
	cin >> n >> k;
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