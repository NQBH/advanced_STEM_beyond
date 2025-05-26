#include <iostream>
using namespace std;
int main(){
	double x, tong = 0.0;
	for(int i=1; i<=12; i++){
		cin >> x;
		tong += x;
	}
	cout << tong/12.0;
	return 0;
}