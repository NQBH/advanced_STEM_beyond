#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	long long Sm = 0, M;
	cout << "Nhap n:";
	cin >> n;
	cout << "Nhap m:";
	cin >> m;
	cout << "Nhap M:";
	cin >> M;
	for (int i = 1; i <= n ; i++) {
		long long S = pow(i, m);
		if (Sm + S > M) break;
		Sm += S;
	}
	cout << "Tong Sm lon nhat khong vuot qua M = " << Sm << '\n';
	return 0;
}

