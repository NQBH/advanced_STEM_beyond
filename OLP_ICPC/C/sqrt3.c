#include <stdio.h>
#include <math.h>

double sqrt3(double x) {
	double ans;
	if (x == 0) ans = 0;
	else if (x < 0) ans = sqrt3(-x);
	else ans = exp(log(x) / 3); // or ans = pow(x, 1 / 3.0);
	return ans;
}