/*
Source: ACM Mid-Atlantic United States 2001.
IDs for online judges: POJ 1005, ZOJ 1049, UVA 2363.
Status: Accepted
*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926;

double calcR(double x, double y) {
	return sqrt(x * x + y * y);
}

int main() {
	int properties; cin >> properties;

	for (int property = 1; property <= properties; property++) {		
		double x, y; cin >> x >> y;

		int yearEnd = 1;
		double S = 50.0;
		double R = sqrt(2 * S / PI);

		int l = 1;
		int r = 1e9 + 7;

		while (l <= r) {
			int mid = l + r >> 1;
			S = 50.0 * mid;
			R = sqrt(2 * S / PI);
			if (calcR(x, y) >= R) {
				l = mid + 1;
			}
			else {
				yearEnd = mid;
				r = mid - 1;
			}
		}

		cout << "Property " << property << ": This property will begin eroding in year " << yearEnd << "." << endl;
	}
	cout << "END OF OUTPUT.";
}