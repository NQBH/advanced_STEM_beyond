#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << a[i][j] << " ";
		cout << '\n';
	}
	for (int i = 0; i < n; ++i) a[i][i] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << a[i][j] << " ";
		cout << '\n';
	}
}