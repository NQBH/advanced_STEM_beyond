#include <iostream>
#include <cmath>
using namespace std;


double tinh_ham_f(double x, double a, double b, double c)
{
    return a * x * x + b * x + c;
}

double tinh_day_F(int n, double a, double b, double c, double a0)
{
    if (n == 0) return a0;

    double gia_tri = a0;

    for (int i = 1; i <= n; i++)
    {
        gia_tri = tinh_ham_f(gia_tri, a, b, c);
    }

    return gia_tri;
}

int main()
{
    int n;
    double a, b, c;
    double a0;

    cin >> n;
    cin >> a >> b >> c;
    cin >> a0;

    cout << tinh_day_F(n, a, b, c, a0);

    return 0;
}
