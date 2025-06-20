#include<iostream>
#include<algorithm>
using namespace std;
int n3(int a) {
	int count = 1;
	while (a!=1) {
		if (a % 2 == 0)a/= 2;
		else a=3 * a + 1;
		count++;
	}
	return count;
}

int main() {
	int a, b;
	while (true) {
		cin >> a >> b;
		int mx = 0;
		for (int i = min(a, b);i <= max(a, b);i++) {
			if (i > mx) mx = max(mx, n3(i));
		}
		cout << a << " " << b << " " << mx << "\n";
	}
}