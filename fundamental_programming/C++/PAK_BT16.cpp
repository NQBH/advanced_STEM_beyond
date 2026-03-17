#include <iostream>
using namespace std;


double f(double a, double b, double c, double x ) {
    double y = a * x * x + b * x + c;
    return y;
}

double F (int n , double alpha) {
    double a, b, c;
    cin >> a >> b >> c;
    for (int i = 2; i <= n; i++) {
        alpha = f(a, b, c, alpha) ;
    }
    return alpha;
}
int main () {
    int n;
    double alpha;
    cin >> n >> alpha ;
    cout << "a" << n << " = " << F(n, alpha);
}