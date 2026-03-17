#include <iostream>
#include <cmath>
using namespace std;

double F(double a, double x,  double n){
    return a * pow(x,n);
}
double f(double k, double l, double m){
    return k * m * pow(l, m - 1);
}
double f2(double k, double l, double m){
    return m*(m-1)*k*pow(l,m-2);
}

int main() {
    double x, a, n, k, l, m;
    cin >> a >> x >> n >> k >> l >> m;
    cout << F(a, x, n) << endl;
    cout << f(k,l,m) <<endl;
    cout << f2(k,l,m) << endl;
}

