#include <bits/stdc++.h>
using namespace std;
int main(){
	float x, y;
	int n, kq;
	cin >> n;
	for (int i = 0; i < n ; ++i) {
		cin >> x >> y;
		kq = ((M_PI*(x*x + y*y))/100) + 1;
		cout << "Property " << i + 1 << ": This property will begin eroding in year "<< kq << ".\n";
	}
	cout << "END OF OUTPUT";
	return 0;
}