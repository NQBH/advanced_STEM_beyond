#include <iostream>
#include <cmath>
using namespace std;
double f(double a, double b, double c, double x){
    return a * x * x + b * x + c;
}
double F(int n, double a, double b, double c, double alpha){
    double res = alpha;
    for (int i = 1; i <= n; i++){
        res = f(a, b, c, res);
    }
    return res;
}
int main(){
    int n = 2;
    double a = 1.0, b = 1.0, c = 1.0, alpha = 1;
    cout << F(n, a, b, c, alpha) << endl;
    return 0;
}