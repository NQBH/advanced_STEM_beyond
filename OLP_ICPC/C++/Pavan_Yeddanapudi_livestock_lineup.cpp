#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string names[] = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};

int main() {
	int n;
	cin >> n;
	vector<pair<string, string>> pairs;
	sort(names, names + 8);
	for (int i = 0; i < n; ++i) {
		string t; // to contain trash words
		pair<string, string> p;
		cin >> p.first >> t >> t >> t >> t >> p.second;
		pairs.push_back(p);
	}
	do {
		bool add = true;
		for (pair<string, string> p : pairs)
			for (int i = 0; i < 8; ++i) {
				if (p.first == names[i] && i > 0 && i < 7)
					if (p.second != names[i - 1] && p.second != names[i + 1]) add = false;
				if (p.first == names[i] && i == 0 && p.second != names[i + 1]) add = false;
				if (p.first == names[i] && i == 7 && p.second != names[i - 1]) add = false;
			}
		if (add) break;
	} while (next_permutation(names, names + 8));
	for (string name : names) cout << name << '\n';
}