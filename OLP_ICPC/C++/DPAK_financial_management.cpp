/*
Source: ACM Mid-Atlantic United States 2001.
IDs for online judges: POJ 1004, ZOJ 1048, UVA 2362
Status: Accepted 
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double ans = 0.0;
	for (int i = 1; i <= 12; i++) {
		double x; cin >> x;
		ans += x / 12.0; 
	}

	cout << "$" << fixed << setprecision(2) << ans;
	return 0;
}