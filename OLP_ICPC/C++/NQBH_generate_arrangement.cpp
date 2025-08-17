#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> current_arrangement;

void print_arrangement() {
	for (int i : current_arrangement) cout << i << " ";
	cout << '\n';
}

void generate_arrangement(int pos, int x) { // generate arrangements starting with x
	current_arrangement.push_back(x);
	bool flag;
	for (int i = 1; i <= n && i != x; ++i) {
		flag = true;
		for (size_t j = 0; j < current_arrangement.size(); ++j)
			if (current_arrangement[j] == i) {
				flag = false; // cannot add i into current arrangement due to duplication
				break;
			}
		if (flag == false) continue;
		else { // can add i into current arrangement
			current_arrangement.push_back(i);
			if (current_arrangement.size() == k) print_arrangement();
			else generate_arrangement(pos + 1, x);
			current_arrangement.pop_back();
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		current_arrangement.clear();
		generate_arrangement(1, i);
	}
}