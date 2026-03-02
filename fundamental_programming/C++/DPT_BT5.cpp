#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, x;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    if (a != 0) {
        x = -b / a;
        cout << "phuong trinh co gia tri x = " << x;
    }
    else {
        (a = 0);
        cout << "phuong trinh vo nghiem ";
        if (b != 0)
            cout << "phuong trinh vo nghiem ";
        else
            cout << "phuong trinh vo so nghiem ";
    }

}