#include <iostream>
using namespace std;
double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}
double F(int n, double alpha, double a, double b, double c) {
    double AA = alpha;
    for (int i = 1; i <= n; i++) {
        AA = f(AA, a, b, c);
    }
    return AA;
}
int main()
{
    int n;
    double a, b, c, alpha;
    cin >> n >> a >> b >> c >> alpha;
    double ketqua = F(n, alpha, a, b, c);
    cout << ketqua << "\n";
    return 0;
}