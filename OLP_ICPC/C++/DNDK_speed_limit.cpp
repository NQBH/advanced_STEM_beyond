#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n and n > 0) {
		int total_miles = 0;
		int lst = 0;
		int v, t;
		for (int i = 0; i < n; ++i) {
			cin >> v >> t;
			total_miles += (t - lst) * v;
			lst = t;
		}
		cout << total_miles << " miles\n";
	}
}