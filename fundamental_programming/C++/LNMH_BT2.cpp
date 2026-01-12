#include <iostream>
#include <math.h> 
using namespace std ;
int main (){
	int a , b ;
	cin >> a >> b ;
	// tính chu vi hình chữ nhật 
	int P = ( a + b ) * 2 ;
	cout << " chu vi hcn = " <<P <<'\n';
	// tính diện tích hình chữ nhật  
	int S = a * b ;
	cout << " dien tich hcn = " <<S <<'\n';
	// tính đường chéo hình chữ nhật
	double DC = sqrt( a * a + b * b) ;
	cout << " duong cheo hcn = " << DC <<'\n';
	return 0;
}
