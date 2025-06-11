#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<int> day1, day2;
bool check[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	ll sum = n * (n + 1LL) / 2;
	if (sum % 2 != 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	ll set_1 = 0, max_element = n;
	while (set_1 < sum / 2) {
		ll remaining = sum / 2 - set_1;
		if (remaining > max_element) {
			day1.push_back(max_element);
			check[max_element] = true;
			set_1 += max_element;
			max_element--;
		} else {
			day1.push_back(remaining);
			check[remaining] = true;
			set_1 = sum / 2;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!check[i])
			day2.push_back(i);

	cout << day1.size() << endl;
	for (int i = 0; i < day1.size(); ++i)
		cout << day1[i] << " ";
	cout << endl;

	cout << day2.size() << endl;
	for (int i = 0; i < day2.size(); ++i)
		cout << day2[i] << " ";
	cout << endl;

	return 0;
}