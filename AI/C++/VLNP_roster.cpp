#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cout << "m = ";
	cin >> m;
	cout << "n = ";
	cin >> n;	
	vector<int> t = { 4, 9, 5, 2, 7, 6, 10, 8, 7, 5 };
	vector<int> d(m, 0);

	sort(t.begin(), t.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		int current_max_work = t[0];
		t.erase(t.begin());
		sort(d.begin(), d.end());
		d[0] += current_max_work;
	}
	cout << "Thoi gian hoan thanh toi da: " << *max_element(d.begin(), d.end()) << endl;
	cout << "Phan cong cu the:" << endl;
	for (int i = 0; i < m; i++) {
		cout << "May " << i + 1 << ": Tong thoi gian = " << d[i] << endl;
	}

	return 0;
}