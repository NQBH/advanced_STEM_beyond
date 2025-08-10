#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> a(m), b(n), c;
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	int i = 1, j = 1;
	while (i < m || j < n)
		if (j == n || (i <= m ))
}