#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int n , m;
	cout << "nhập n :" ;
	cin >> n;
	cout << "nhập m :";
	cin >> m;

	double S = 0;
	for (int i = 1; i <= n ; i++) {
		S += pow(i, m);
	}
	cout << "S = " << S << endl;

}

