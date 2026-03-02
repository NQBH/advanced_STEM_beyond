#include <iostream>
using namespace std;

int main() {
	double n, N, max, min;
	cout << "nhap so luong so thuc "; cin >> n;
	if (n <= 0) {
		cout << "error" << endl;
	}
	cout << "so thuc dau  = "; cin >> N;
	max = N;
	min = N;
	for (int i = 1; i <= n; ++i) {
		cout << "nhap so thuc thu tiep theo " << i << "= "; cin >> N;
		if (max < N) {
			max = N;
		}
		if (min > N) {
			min = N;
		}
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	return 0;
}
