#include <iostream>
#include <cmath>
using namespace std;

// BT16
// hàm f(x)= a*x^2 + b*x + c
double f(double a, double b, double c, double x)
{
    return a * x * x + b * x + c;
}

// hàm tính a_n
double a_n(int n, double alpha, double a, double b, double c)
{
    double an = alpha;

    for (int i = 0; i < n; i++)
    {
        an = f(a, b, c, an);
    }

    return an;
}

// BT17
// hàm f(x) = a*x^n
double fx(double a, double x, int n)
{
    return a * pow(x, n);
}

// f'(x)
double df(double a, double x, int n)
{
    return n * a * pow(x, n - 1);
}

// f''(x)
double d2f(double a, double x, int n)
{
    return n * (n - 1) * a * pow(x, n - 2);
}

int main()
{
    double a, b, c, alpha;
    int n;

    cout << "Nhap gia tri cua a, b, c: " << endl;
    cin >> a >> b >> c;

    cout << "Nhap gia tri cua alpha: " << endl;
    cin >> alpha;

    cout << "Nhap gia tri cua n: " << endl;
    cin >> n;

    double result = a_n(n, alpha, a, b, c);

    cout << "a_" << n << " = " << result << endl;

    double x;

    cout << "Nhap gia tri cua a, x, n: " << endl;
    cin >> a >> x >> n;

    cout << "Nhap f(x) = " << fx(a, x, n) << endl;
    cout << "Nhap f'(x) = " << df(a, x, n) << endl;
    cout << "Nhap f''(x) = " << d2f(a, x, n) << endl;
}