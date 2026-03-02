#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double n;
    cout << "n = ";
    cin >> n;
    double a = 0; //a la dem so 0
    double b = 0; //b la dem so am
    double c = 0; //c la dem so duong
    for (int i = 0; i < n; ++i) {
        double x;
        cout << "x = ";
        cin >> x;
        if (x == 0) {
            a ++;
        } else if (x > 0) {
            c ++;
        } else b++;
    }
    {
        cout << "dem so so 0 = " << a << '\n';
        cout << "dem so so am = " << b << '\n';
        cout << "dem so so duong = " << c << '\n';
    }
}