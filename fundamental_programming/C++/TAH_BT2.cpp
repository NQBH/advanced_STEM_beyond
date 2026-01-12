#include <iostream>
using namespace std ;
int main (){
	int a ;
	int b;
	cin >> a ;
	cin >> b ;
	// tính chu vi hình chữ nhật
	int C = (a + b) *2;
	// tính diện tích hình chữ nhật
	int S = a * b ;
	cout << "chu vi hình chữ nhật a  = " << a << b << " bang "<< C << '\n';
	cout << "diện tích hình chữ nhật a  = "  << a << b <<" bang " << S << '\n';
	return 0;
}