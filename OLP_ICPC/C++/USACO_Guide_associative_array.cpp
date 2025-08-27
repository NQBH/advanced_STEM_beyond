#include <iostream>
#include <map>
using namespace std;

int main() {
	int query_num;
	cin >> query_num;
	map<long long, long long> a; // map to store only assigned indices
	for (int q = 0; q < query_num; ++q) {
		int t;
		cin >> t;
		if (t == 0) {
			long long k, v;
			cin >> k >> v;
			a[k] = v;
		} else if (t == 1) {
			long long k;
			cin >> k;
			cout << a[k] << '\n'; // if k is not in the map, operator [] returns 0 by default
		}
	}
}