/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //double sqrt(double x)
    double x;
    cin >> x;
    if (x < 0)
        cout << "x must be nonnegative\n";
    else
        cout << sqrt(x) << '\n';
    
    //double pow (x, y)
    double a, b;
    cin >> a >> b;
    if (x <= 0)
        cout << "x must be nonnegative\n";
    else
        cout << pow(a, b) << '\n';
        
    //double exp (x)
    double y;
    cin >> y;
    if (x < 0)
        cout << "x must be nonnegative\n";
    else
        cout << exp(y) << '\n';
    // double log   
    double c;
    cin >> c;
    if (c <= 0)
        cout << "x must be nonnegative\n";
    else
        cout << log(c) << '\n';
    // double log10    
    double d;
    cin >> d;
    if (d <= 0)
        cout << "x must be nonnegative\n";
    else
        cout << log10(x) << '\n';
        
    // int ads(int x)
    // long labs(long x)
    // double fabs (double x)
    int x1;
    long x2;
    double x3;
    
    cin >> x1;
    cin >> x2;
    cin >> x3;
    
    cout << abs(x1) << '\n';
    cout << labs(x2) << '\n';
    cout << fabs(x3) << '\n';
    
    // double cin cos tan
    double t;
    cin >> t;
    cout << sin(t) << '\n';
    cout << cos(t) << '\n';
    cout << tan(t) << '\n';
    
    //double acin acos atan
    double l;
    cin >> l;
    if (x < -1 || x > 1)
    cout << "x must be in [-1,1]";
else
    cout << acos(l) << '\n';
    cout << asin(l) << '\n';
    cout << atan(l) << '\n';
    
    //double floor, ceil
    double k;
    cin >> k;
    cout << floor(k) << '\n';
    cout << ceil(k) << '\n';
    return 0;
}
