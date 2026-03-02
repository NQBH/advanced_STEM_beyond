#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	long long Sm = 0;
	cout << "Nhap m:";
	cin >> m;
	cout << "Nhap n:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		Sm += pow(i, m);
	}
	cout << "Tong Sm = " << Sm << '\n';
	return 0;
}