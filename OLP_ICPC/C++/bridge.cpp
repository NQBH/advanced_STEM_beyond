#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;
int n,i,j,k,a[111111]; // n: number of persons, a[]: n people's crossing times
int ans = 0; // ans: total number of seconds for all n people to cross the bridge
int main() {
	scanf("%d", &n); // input
	for (i = 1; i <= n; ++i)
		scanf("%d", a+i); // pointer?
	if (n == 1) { // only 1 person
		printf("%d\n%d\n", a[1], a[1]);
		return 0;
	}
	int nn = n;
	sort(a+1, a+n+1); // n people's crossing times are sorted in descending order
	while (n > 3) { // calculate total number of seconds for all n people to cross the bridge
		if (a[1] + a[n-1] < 2*a[2]) // method 1: A + b < 2B
			ans += a[1]*2 + a[n-1] + a[n]; // acummulated time: 2A + a + b
		else // method 2
			ans += a[1] + 2*a[2] + a[n]; // acummulated time: A + 2B + a
		n -= 2; // 2 slowest persons cross the bridge
	}
	if (n == 2)
		ans += a[2]; // only 2 persons need to cross the bridge
	else
		ans += a[1] + a[2] + a[3]; // 3 persons need to cross the bridge
	printf("%d\n",ans); // total number of seconds for all n people to cross the bridge
	n = nn;
	while (n > 3) { // output the strategy to achieve this time
		if (a[1] + a[n-1] < 2*a[2]) // method 1
			printf("%d %d\n%d\n%d %d\n%d\n",a[1],a[n],a[1],a[1],a[n-1],a[1]);
		else // method
			printf("%d %d\n%d\n%d %d\n%d\n",a[1],a[2],a[1],a[n-1],a[n],a[2]);
		n -= 2; // 2 slowest persons cross the bridge
	}
	if (n == 2)
		printf("%d %d\n",a[1],a[2]); // only 2 persons need to cross the bridge
	else // 3 persons need to cross the bridge
		printf("%d %d\n%d\n%d %d\n",a[1],a[3],a[1],a[1],a[2]);
	return 0;
}