# include <bits/stdc++.h>
using namespace std;

double F(double a, double x,  double n){
    return a * pow(x,n);
}
double f_prime(double A, double X, double N){
    return A * N * pow(X, N-1);
}
double f_prime2(double A, double X, double N){
    return N*(N-1)*A*pow(X,N-2);
}

int main() {
    double x, a, n, A, X, N;
    cin >> a >> x >> n >> A >> X >> N;
    cout << F(a, x, n) << endl;
    cout << f_prime(A,X,N) << endl;
    cout << f_prime2(A,X,N) << endl;
}