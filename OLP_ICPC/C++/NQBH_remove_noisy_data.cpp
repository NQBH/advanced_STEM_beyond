#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, num0 = 0, num_pos = 0, num_neg = 0;
	cin >> n;
	vector<int> a(n), pos, neg;
	for (int& x : a) {
		cin >> a;
		if (a == 0) ++num0;
		else if (a > 0) {
			++num_pos;
			pos.push_back(a);
		}
		else {
			++num_neg;
			neg.push_back(a);
		}
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	if (num0 == 0) {

	} else if (num0 == 1) {

	}
	else { // if (num0 > 1)
		cout << pos.back() << " " << neg[0];
	}
}