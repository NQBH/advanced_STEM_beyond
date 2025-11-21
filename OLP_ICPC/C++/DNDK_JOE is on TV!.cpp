#include<bits/stdc++.h>
using namespace std;
int main() {
	double n;
	double ans = 1;
	cin >> n;
	while (n > 1) {
		ans += 1 / n;
		n--;
	}
	cout << ans << endl;
}
