#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,m;
	double S=0;
	cout <<"Nhap n: ";
	cin >> n;
	cout <<"Nhap m: ";
	cin >> m;
	for ( int i = 1; i<=n; ++i){
		S += pow(i,m);
	
	}
	cout << "So mu = " << S << endl;
	return 0;
}