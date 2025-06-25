#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int x, int A, int B, int C) {
	if (x == 1) {
		cout << A << " " << C << "\n";
		return;
	}
	Hanoi(x - 1, A, C, B);
	cout << A << " " << C << "\n";
	Hanoi(x - 1, B, A, C);
}
int main() {
	int n;
	cin >> n;
	double x = pow(2, n) - 1;
	cout << x << "\n";
	Hanoi(n, 1, 2, 3);
	return 0;
}