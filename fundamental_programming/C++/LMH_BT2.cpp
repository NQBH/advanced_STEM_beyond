#include <cmath>
#include <iostream>
using namespace std;

int main() {
	float a;   //CD
	float b;   //CR
	float c;
	float S;
	float C;
	cout << "nhap CD =";
	cin >> a;
	cout << "nhap CR =";
	cin >> b;
	if (a > 0 & b > 0) {
		c = sqrt(a * a + b * b);
		cout << "Ðg chéo HCN =" << c << '\n';
		S = a * b;
		cout << " dien tich HCN  =" << S << '\n';
		C = (a + b) * 2;
		cout << " chu vi HCN =" << C << '\n';
	}
	else {
		cout << "Không có giá tri" << '\n';
	}
	return 0;
}
