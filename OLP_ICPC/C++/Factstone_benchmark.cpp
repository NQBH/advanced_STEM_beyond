#include <stdio.h>
#include <math.h>
int y;

int main() {
	while (1 == scanf("%d", &y) && y) { // input test cases
		double w = log(4);
		for (int Y = 1960; Y <= y; Y += 10)
			w *= 2;
		int i = 1; // accumulation log2 i until > w
		double f = 0; // f: sum of accumulation for log2 i
		while (f < w)
			f += log((double)++i);
		printf("%d\n", i - 1); // output Factstone rating
	}
	if (y) printf("fishy ending %d\n", y);
}