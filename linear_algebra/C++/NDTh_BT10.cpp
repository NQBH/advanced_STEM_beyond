#include<iostream>
using namespace std;

int main(){
	int a,b,c,d;
	cout << " nhap cac so phan tu";
	cin >> a >> b >> c >> d;
	if (a <=0 ||b <=0 ||c <=0 || d <= 0){
		cout << " nhap lai di! :";
		return 1;
	}
	cout << "a x d " << a * d <<endl;
	cout << " b x c " << b * c << endl;
	cout << " tinh dinh thuc cua ma tran 2 x 2"<< a * d - b * c ;
	return 0;
}
