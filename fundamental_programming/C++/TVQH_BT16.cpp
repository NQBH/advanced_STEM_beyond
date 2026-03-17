#include <iostream>
#include <cmath>
using namespace std;

const double CONST_A = 1.0;
const double CONST_B = 1.0;
const double CONST_C = 1.0;
double f(double a, double b, double c, double x) {
    return (a * x * x) + (b * x) + c;
}
double F(int n, double alpha) {
    double a_n = alpha; // a_0 = alpha
    for (int i = 0; i < n; ++i) {
        // a_{n+1} = f(a_n)
        a_n = f(CONST_A, CONST_B, CONST_C, a_n);
    }
    return a_n;
}