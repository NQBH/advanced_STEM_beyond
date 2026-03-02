#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
	double x, y;
	cout << "nhập số x: ";
	cin >> x;
	if (x < 0) cout << "x phải lớn hơn hoặc bằng 0" << '\n';
	else cout << "căng bậc hai của " << x << ": " << sqrt(x) << '\n';
	cout << "nhập số y: " << '\n';
	cin >> y;
	pow(x, y);
	if (x <= 0) cout << "x phải lớn hơn 0";
	else cout << "x lũy thừa y: " << pow(x, y) << '\n';
	cout << "e mũ x : " << exp(x) << '\n';
	cout << "logarit cơ số e của x: " << log(x) << '\n';
	cout << "logarit cơ số 10 của x : " << log10(x) << '\n';
	int a;
	cout << "nhập số a: ";
	cin >> a;
	cout << "giá trị tuyệt đối |a| với a nguyên: " << abs( a) << '\n';
	long b;
	cout << "nhập số b: ";
	cin >> a;
	cout << "giá trị tuyệt đối |b| với b nguyên dài: " << abs( b) << '\n';
	double c;
	cout << "nhập số c: ";
	cin >> c;
	cout << "giá trị tuyệt đối |c| với c là số thực: " << abs( c) << '\n';
	cout << "sin(x): " << sin(x) << '\n';
	cout << "cos(x): " << cos(x) << '\n';
	cout << "tan(x): " << tan(x) << '\n';
	cout << "hàm lượng giác ngược arcsin(x): " << asin(x) << '\n';
	cout << "hàm lượng giác ngược arccos(x): " << acos(x) << '\n';
	cout << "hàm lượng giác ngược arctan(x): " << atan(x) << '\n';
	cout << "số nguyên lớn nhất không vượt quá x: " << floor(x) << '\n';
	cout << "số nguyên nhỏ nhất lớn hơn hay bằng x: " << ceil(x) << '\n';
}


