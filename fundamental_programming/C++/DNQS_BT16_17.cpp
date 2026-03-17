#include<iostream>
#include<cmath>
using namespace std;

// BT16
// hàm f(x)=a*x^2+b*x+c
double f(double a, double b, double c, double x)
{
    return a * x * x + b * x + c;
}

// hàm tính a_n
double a_n(int n , double alpha, double a, double b , double c)
{
    double an = alpha ;
    for (int i = 0; i < n; i++)
    {
        an = f(a, b, c, an);
    }
    return an;
}

//BT17
// hàm f(x)=a*x^n
double f(double a, double x, double n)
{
    return n * a * pow(x, n - 1);
}
double D2f(double a, double x, double n)
{
    return n * (n - 1) * a * pow(x, n - 2);
}

int main() {
    double a, b, c, alpha;
    int n;
    cout << "Nhap a16, b16, c16: ";
    cin >> a >> b >> c;
    cout << "Nhap alpha16: ";
    cin >> alpha;
    cout << "Nhap n16: ";
    cin >> n;

    double result = a_n(n, alpha, a, b, c);
    cout << "a_" << n << " = " << result << endl;

    double a17, x17, n17;
    cout << "Nhap a17, x17, n17: ";
    cin >> a17 >> x17 >> n17;
    cout << "f'(x) = " << f(a17, x17, n17) << endl;
    cout << "f''(x) = " << D2f(a17, x17, n17) << endl;
    return 0;
}
