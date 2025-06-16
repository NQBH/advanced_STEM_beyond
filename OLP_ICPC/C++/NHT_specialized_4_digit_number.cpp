#include <bits/stdc++.h>
#define ll long long
using namespace std;

int calc(int k, int b) {
	int a[5], i = 0, sum = 0;
	while (k) {
		a[i] = k % b;
		k /= b;
		++i;
	}
	--i;
	for (int j = i; j >= 0; --j)
		sum += a[j];
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 2991; i <= 9999; ++i) {
		int s = i % 10 + (i / 10) % 10 + (i / 100) % 10 + i / 1000;
		if (s == calc(i, 12) && s == calc(i, 16))
			cout << i << endl;
	}
	return 0;
}