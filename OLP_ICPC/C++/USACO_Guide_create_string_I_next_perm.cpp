#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector<string> perms; // perms is a sorted list of all the permutations of the given string
	do perms.push_back(s); while (next_permutation(s.begin(), s.end()));
	cout << perms.size() << '\n';
	for (const string &perm: perms) cout << perm << '\n';
}