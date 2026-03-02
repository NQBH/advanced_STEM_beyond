#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	long long Sm = 0;
	cin >> n >> m;
	for ( int i = 0; i <= n; ++i)
	{ Sm += pow(i, m);}
	cout << Sm;
	return 0;
}