/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

double f(double& a, double& b, double& c, double& x)
{
    return a * x * x + b * x + c;
}

double F(int &n, double &alpha, double &a, double &b, double &c)
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

    cout << "a_n = " << F(n, alpha, a, b, c);

    return 0;
}