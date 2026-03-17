# include <bits/stdc++.h>
using namespace std;

double F(double a, double x,  double n){
    return a * pow(x,n);
}

int main() {
    double x, a, n;
    cin >> a >> x >> n;
    cout << F(a, x, n) << endl;
}