#include <bits/stdc++.h>
using namespace std;
int getMaxDigit(int x){
	int maxDigit = 0;
	while (x > 0){
		int d = x % 10;
		if (d > maxDigit)
			maxDigit = d;
		x /= 10;
	}
	return maxDigit;
}
int main(){
	int n, steps = 0;
	cin >> n;
	while (n > 0){
		int d = getMaxDigit(n);
		n-=d;
		steps++;
	}
	cout << steps << '\n';
	return 0;
}