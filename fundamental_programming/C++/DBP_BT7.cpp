#include <iostream>
using namespace std;
int main() {
//cau a
    double a, b, c, max, min;
    cout << "nhap so thuc a,b,c" << '\n';
    cin >> a >> b >> c;
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    if (c > max)
        max = c;
    else if (c < min)
        min = c;

    cout << "max = " << max << endl;
    cout << "min = " << min << endl;
//cau b
    int n;
    cout << " n la so thuc: ";
    cin >> n;
    double x;
    cin >> a >> b;
    if ( a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    for (int i = 3; i <= n; ++i) {
        cin >> x;
        if (x > max)
            max = x;
        else if ( x < max)
            min = x;
    }
    cout << " max: " << max << endl;
    cout << " min: " << min << endl;
}
