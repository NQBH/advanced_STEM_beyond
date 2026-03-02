#include <iostream>
using namespace std;

int main() {
	int  n, a, le = 0, chan = 0;
	cout << " nhap so luong so thuc = "; cin >> n;
	if (n <= 0) {
		cout << "error" << endl;
	}
	else {

		for (int i = 1; i <= n; ++i) {
			cout << "nhap so thuc a " << i << " = "; cin >> a;
			if (a % 2 == 0) {
				chan++;
			}
			else {
				le++;
			}

		}
		cout << "so so chan la : " << chan << endl;
		cout << "so so le la : " << le << endl;
	}
	return 0;
}
