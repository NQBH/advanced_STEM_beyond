#include <stdio.h>
#include <math.h>
int b, b0, y, delta_year, delta_month;
double Y;

int main() {
	/*
	scanf("%f", &y0);
	scanf("%d", &b);
	scanf("%d", &b0);
	scanf("%d", &delta_year);
	scanf("%d", &delta_month);
	*/
	// y0 = 1960.0;
	b = 3;
	delta_year = 1;
	delta_month = 4;
	b0 = 1;
	while (1 == scanf("%d", &y) && y) { // input test cases
		double w = log(pow(b, b0));
		for (Y = 1960; Y <= y; Y += delta_year + delta_month / 12)
			w *= b;
		int i = 1; // accumulation log2 i until > w
		double f = 0; // f: sum of accumulation for log2 i
		while (f < w)
			f += log((double)++i);
		printf("%d\n", i - 1); // output Factstone rating
	}
	if (y) printf("fishy ending %d\n", y);
}