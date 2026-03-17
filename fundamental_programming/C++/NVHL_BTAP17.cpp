#include <iostream>
#include <cmath>
using namespace std;

double f(double a, double x, double n){
    return a * pow(x, n);
}

double DF(double a, double x, double n){
    return n * a * pow(x, n - 1);
}

int main(){
    double a, x ,n;

    cout << "nhap a x n:";
    cin >> a >> x >> n;

    cout << "f(x) = " << f(a, x, n) << endl;
    cout << "f'(x) = " << DF(a, x, n) << endl;
    return 0;
}
