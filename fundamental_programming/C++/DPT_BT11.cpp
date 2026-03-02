#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    double A, B, C;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
    cout << "C = ";
    cin >> C;
    double d = a * B - A * b;
    double dx = c * B - C * b;
    double dy = a * C - A * c;
    if (d != 0)
    {
        double x = dx / d;
        double y = dy / d;
        cout << "he phuong trinh co ham duy nhat ";
        cout << "x = " << x << '\n';
        cout << "y = " << y << '\n';
    }
    else
    {
        if (dx == 0 && dy == 0)
            cout << "he phuong trinh co vo so nghiem " << '\n';
        else
            cout << "he phuong trinh vo nghiem " << '\n';
    }
}