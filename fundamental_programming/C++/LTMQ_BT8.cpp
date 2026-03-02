#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N;
	cin >> N;
	double a, so0, soAm, soDuong;
	for (int i = 1; i <= N; ++i) {
		cin >> a;
		if (a == 0) so0++;
		else if (a > 0) soDuong++;
		else soAm++;
	}
	cout << "so duong trong N bien = " << soDuong << endl;
	cout << "tong so 0 trong N bien = " << so0  << endl;
	cout << "si an trong N bien = " << soAm  << endl;
	return 0;
}
