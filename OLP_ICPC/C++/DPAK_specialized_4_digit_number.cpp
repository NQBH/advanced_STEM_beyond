/*
Source: ACM Pacific Northwest 2004.
IDs for online judges: POJ 2196, ZOJ 2405, UVA 3199.
Status: Accepted
*/
#include <iostream>
using namespace std;

int calc(int n, int base) {
	int ans = 0;
	while (n) {
		ans += n % base;
		n /= base;
	}
	return ans;
}

int main() {
	for (int i = 2991; i <= 9999; i++) {
		int calc10 = calc(i, 10);
		if (calc10 == calc(i, 16) && calc10 == calc(i, 12))
			cout << i << '\n';
	}		
}