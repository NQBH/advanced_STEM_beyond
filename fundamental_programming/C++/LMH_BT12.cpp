#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m, S = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		S += pow(i, m);
	cout << S;
	return 0;
}
