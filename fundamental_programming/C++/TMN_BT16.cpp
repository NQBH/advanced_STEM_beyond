#include <iostream>
using namespace std;
double f(double a, double b, double c, double x)
{
    return a * x * x + b * x + c;
}

double F(int n, double alpha, double a, double b, double c)
{
    double an = alpha;
    for (int i = 0; i < n; i++)
    {
        an = f(a, b, c, an);
    }
    return an;
}
int main()
{
    int n;
    double alpha, a, b, c;

    cin >> n >> alpha;
    cin >> a >> b >> c;

    cout << F(n, alpha, a, b, c);
    return 0;
}