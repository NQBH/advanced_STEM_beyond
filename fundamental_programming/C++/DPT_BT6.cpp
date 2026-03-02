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
    double y = b * b - 4 * a * c; //y la delta
    if (y < 0) {
        cout << "phuong trinh vo nghiem ";
    }
    else if (y == 0) {
        double x = -b / (2 * a);
        cout << "phuong trinh nghiem kep = " << x << '\n';
    }
    else {
        double x1 = -b + sqrt(y) / (2 * a);
        cout << "phuong trinh 2 nghiem thuc = " << x1 << '\n';
        double x2 = -b - sqrt(y) / (2 * a);
        cout << "phuong trinh 2 nghiem thuc = " << x2 << '\n';
    }

}

