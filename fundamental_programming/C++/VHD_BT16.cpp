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

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap alpha: ";
    cin >> alpha;

    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    double result = F(n, alpha, a, b, c);

    cout << "a_n = " << result;

    return 0;
}