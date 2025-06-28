#include <stdio.h>

int is_natural(int n) {
	if (n == 0) return 1;
	else return is_natural(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d is_natural: %d", n, is_natural(n));
	return 0;
}