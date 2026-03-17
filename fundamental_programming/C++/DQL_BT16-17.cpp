#include <iostream>
#include <cmath>
using namespace std;

// Bai16
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

// Bai17
double fx(double a, double x, double n)
{
    return a * pow(x, n);
}

double D1f(double a, double x, double n)
{
    return n * a * pow(x, n - 1);
}

double D2f(double a, double x, double n)
{
    return n * (n - 1) * a * pow(x, n - 2);
}

int main()
{
    // Bai16
    int n;
    double alpha, a, b, c;

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap alpha: ";
    cin >> alpha;

    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    cout << "Gia tri a_n = " << F(n, alpha, a, b, c) << endl;

    // Bai17
    double x;

    cout << "\nNhap x: ";
    cin >> x;

    cout << "f(x) = " << fx(a, x, n) << endl;
    cout << "f'(x) = " << D1f(a, x, n) << endl;
    cout << "f''(x) = " << D2f(a, x, n) << endl;

    return 0;
}