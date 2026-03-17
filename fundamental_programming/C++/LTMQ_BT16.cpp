#include <iostream>
#include <cmath>
using namespace std;
double dsa, dsb, dsc;

double f(double a, double b, double c, double x) {
	return a * x * x + b * x + c;
}
double F( int n, double alpha ) {
	double an = alpha;
	for ( int i = 0; i < n ; i++)
		an = f(dsa, dsb, dsc, an);
	return an;

}
int main() {
	cin >> dsa >> dsb >> dsc;
	int n;
	double alpha;
	cin >> n >> alpha;
	cout << n << " " << F(n , alpha) << '\n';
	return 0;
}