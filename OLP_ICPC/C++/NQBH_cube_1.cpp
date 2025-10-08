#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(k, vector<int>(3));
	set<string> S;
	for (int i = 0; i < k; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][0] == 0) {
			string str1 = to_string(a[i][1]);
			string str2 = to_string(a[i][2]);
			for (int j = 0; j < n; ++j) S.insert(to_string(j) + " " + str1 + " " + str2);
		} 
		else if (a[i][1] == 0) {
			string str0 = to_string(a[i][0]);
			string str2 = to_string(a[i][2]);
			for (int j = 0; j < n; ++j) S.insert(str0 + " " + to_string(j) + " " + str2);
		}
		else {
			string str0 = to_string(a[i][0]);
			string str1 = to_string(a[i][1]);
			for (int j = 0; j < n; ++j) S.insert(str0 + " " + str1 + " " + to_string(j));
		}
	}
	cout << S.size();
}
// AC 20/35 VNOJ. TLE test 21.