#include <math.h>
#include <stdio.h>

int max_real(float a[], int n) {
	// precondition: n >= 1
	int id_max = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] > a[id_max]) id_max = i;
	return id_max;
}

int min_real(float a[], int n) {
	// precondition: n >= 1
	int id_min = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] < a[id_min]) id_min = i;
	return id_min;
}

int best_real(float a[], int n, int (*better)(float, float)) {
	int id_best = 0;
	for (int i = 1; i < n; ++i)
		if (better(a[i], a[id_best])) id_best = i;
	return id_best;
}

int abs_less(float x, float y) {
	return fabs(x) < fabs(y);
}

int frac_greater(float x, float y) {
	x = (float)fabs(x);
	x -= (int)x;
	y = (float)fabs(y);
	y -= (int)y;
	return x > y;
}

int main() {
	float a[] = {-3.4F, 6.7F, -5.92F, 0.229F, -9.08F};
	int n = sizeof(a) / sizeof(a[0]);
	int j = best_real(a, n, abs_less);
	printf("Element minimum abs = %f\n", a[j]);
	j = best_real(a, n, frac_greater);
	printf("Element maximum fraction = %f\n", a[j]);
	return 0;
}