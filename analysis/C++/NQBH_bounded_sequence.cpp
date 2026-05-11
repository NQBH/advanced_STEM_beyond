#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	double M = 0; // initialization of bound M: M < 0: nonlogical since M >= |a_n| >= 0
	vector<double> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		M = max(M, abs(a[i]));
	}
	cout << "The sequence {a_i}_{i=0}^{n-1} is bounded by " << M << " since |a_i| <= " << M << " for all i = 0,1,...," << n - 1 << ".\n";
}