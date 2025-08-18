#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), c;
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	int i = 0, j = 0;
	while (i < n || j < m)
		if (j == m || (i < n && a[i] <= b[j])) c.push_back(a[i++]);
		else c.push_back(b[j++]);
	for (auto it : c) cout << it << " ";
}