#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n && n != 0) {
		vector<vector<double>> a(n, vector<double>(4, 0)), coeff(n, vector<double> (2, 0));
		for (int i = 0; i < n; ++i) {
			cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3]; // xA yA xB yB
			// compute coefficients a, b of line y = ax + b through (xA, yA), (xB, yB)
			// a = (yA - yB)/(xA - xB), b = yA - xA * a
			coeff[i][0] = (a[i][3] - a[i][1]) / (a[i][2] - a[i][0]);
			coeff[i][1] = a[i][1] - coeff[i][0] * a[i][0];
			// cout << coeff[i][0] << coeff[i][1] << '\n';
		}

		for (int i = 0; i < n; ++i) {
			
		}
		

	}
}