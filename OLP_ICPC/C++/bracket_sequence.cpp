#include <cstdio>
#include <cstring>

const int N = 100;
char str[N]; // input string
int dp[N][N], path[N][N];

void oprint(int i, int j) { // output regular brackets sequence containing subsequence str[i, j]
	if (i > j) return;
	if (i == j) { // there is only 1 character for subsequence str[i, j]
		if (str[i] == '[' || str[i] == ']') printf("[]");
		else printf("()");
	}
	else if (path[i][j] == -1) { // str[i] & str[j] are matched brackets
		printf("%c", str[i]);
		oprint(i + 1, j - 1);
		printf("%c", str[j]);
	}
	else {
		oprint(i, path[i][j]);
		oprint(path[i][j] + 1, j);
	}
}

int main(void) {
	while (fgets(str, sizeof(str), stdin)) { // error: 'gets' was not declared in this scope; did you mean 'getw'?
		int n = strlen(str);
		if (n == 0) {
			printf("\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) dp[i][i] = 1;
		for (int r = 1; r < n; ++r) { // stage: r is the length of subsequences
			for (int i = 0; i < n - r; ++i) { // state: fronts of subsequences are enumerated
				int j = i + r; // rears of subsequences
				dp[i][j] = 0x7fffffff; // initialization: in C++, 0x7fffffff is a hexadecimal literal representing the maximum positive value that a 32-bit signed integer can hold.
				if ((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']')) { // str[i] & str[j] are matched
					dp[i][j] = dp[i + 1][j - 1];
					path[i][j] = -1;
				}
				for (int k = i; k < j; ++k) // k is enumerated
					if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
						dp[i][j] = dp[i][k] + dp[k + 1][j];
						path[i][j] = k;
					}
			}
		}
		oprint(0, n - 2); // output the regular brackets sequence: original oprint(0, n - 1);
		printf("\n");
	}
	return 0;
}