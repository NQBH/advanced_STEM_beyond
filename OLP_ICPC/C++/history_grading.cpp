#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n; // number of events
int f[30][30], st[30], ed[30], tmp[30]; // st[t] is t-th event in chronological order, ed[t] is t-th event in current student's chronological order

int main(void) {
	scanf("%d", &n); // input number of events
	for (int i = 1; i <= n; ++i) { // input correct chronological order of n events
		cin >> tmp[i];
		st[tmp[i]] = i;
	}
	while (!cin.eof()) { // input students' chronological ordering of n events
		for (int i = 1; i <= n; ++i) { // input current student's chronological ordering of n events
			cin >> tmp[i];
			ed[tmp[i]] = i;
		}
		if (cin.eof()) break; // use if there is a blank line at the end of input file
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; ++i) // calculate LCS for st[] & ed[]
			for (int j = 1; j <= n; ++j) {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (st[i] == ed[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
		cout << f[n][n] << '\n'; // output current student's score
	}
}