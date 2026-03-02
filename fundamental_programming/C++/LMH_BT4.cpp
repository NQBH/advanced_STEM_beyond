#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x, y, e, pi;
	cin >> x;
	cin >> y;
	if (x < 0) {
		cout << "error" << '\n';
	}
	else {
		cout << "can bac 2 cua x = " << sqrt(x) << endl;
	}
	if (x <= 0) { //do log(0) vô n0
		cout << "error" << '\n';
	}
	else {
		//tính x luy th?a y v?i x>0
		cout << " x^y = " << pow(x, y) << endl;
		cout << "log10(x)= " << log10(x) << endl;
		cout << "log(x)= " << log(x) << endl;
	}
	e = 2.71828;
	cout << "e^x = " << pow(e, x) << endl;
	cout << "|x|= " << abs(x) << endl;
	pi = 3.14159;

	cout << "sin(x)= " << sin(x) << endl;
	cout << "cos(x)= " << cos(x) << endl;
	cout << "tan(x)= " << tan(x) << endl;
	if (-1 <= x <= 1) {
		cout << "arcsin(x): " << asin(x) << endl;
		cout << "arccos(x): " << acos(x) << endl;
		cout << "arctan(x): " << atan(x) << endl;
	}
	else {
		cout << "error";
	}
	cout << "so nguyen lon nhat khong vuot qua x = " << floor(x) << endl;
	cout << "so nguyen nho nhat hay bang x = " << ceil(x) << endl;

	return 0;
}
