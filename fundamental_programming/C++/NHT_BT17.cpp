/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

double f(double &a, double &x, double &n)
{
    return a * pow(x, n);
}

double D1(double &a, double &x, double &n)
{
    return n * a * pow(x, n - 1);
}

double D2(double &a, double &x, double &n)
{
    return n * (n - 1) * a * pow(x, n - 2);
}

int main()
{
    double a, x, n;

    cout << "Nhap a x n: ";
    cin >> a >> x >> n;

    cout << "f(x) = " << f(a, x, n) << endl;
    cout << "f'(x) = " << D1(a, x, n) << endl;
    cout << "f''(x) = " << D2(a, x, n) << endl;

    return 0;
}
