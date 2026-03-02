#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c, vmax, vmin;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    if (a > b && b > c) {
        vmax = a;
        cout << "Max: " << vmax << '\n';
    } else if (b > a && a > c) {
        vmax = b;
        cout << "Max: " << vmax << '\n';
    } else {
        vmax = c;
        cout << "Max: " << vmax << '\n';
    }
    if (a < b && b < c) {
        vmin = a;
        cout << "Min: " << vmin << '\n';
    } else if (b < a && a < c) {
        vmin = b;
        cout << "Min: " << vmin << '\n';
    } else {
        vmin = c;
        cout << "Min: " << vmin << '\n';
    }
    return 0;
}