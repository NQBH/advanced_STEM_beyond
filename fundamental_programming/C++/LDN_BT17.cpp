#include<iostream>
#include<cmath>
using namespace std;
double f(double a, double x, double n) {
    return a * pow(x, n);
}
double Df(double a, double x, double n){
    return n * a * pow(x, n - 1);

}
double D2f(double a, double x, double n){
    return n * (n - 1)* a * pow(x,n - 2);
}

int main(){
    double a = 2.0, x = 3.0, n = 2.0;
    cout << f(a, x, n) << endl;
    cout << Df(a, x, n) << endl;
    cout << D2f(a, x, n) << endl;
    return 0;
}