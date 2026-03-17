#include <iostream>
#include <cmath>
using namespace std;
double luythua(double x, double n) {
    /* double ans = 1;
     bool am = false;
     if (n < 0) {n = -n; am = true;}
     for (int i = 1; i <= n; i++){
         ans*=x;
     }
     if(am){return 1/ans;}
     else{return ans;}*/
    return pow(x, n);

}
double f(double a , double x, double n) {
    return a * luythua(x, n);
}

double Df(double a, double x, double n) {
    return a * n * luythua(x, n - 1);
}
double D2f(double a, double x, double n) {
    return a * n * (n - 1) * luythua(x, n - 2);
}
int main() {
    double a, x, n;
    cin >> a >> x >> n;
    cout << "ham f(x) = ax^n" << '\n';
    cout << " Gia tri ham f(x) = " << f(a, x, n) << '\n';
    cout << " Gia tri dao ham lan 1 cua f(x) = " << Df(a, x, n) << '\n';
    cout << " Gia tri dao ham lan 2 cua f(x) = " << D2f(a, x, n) << '\n';
}