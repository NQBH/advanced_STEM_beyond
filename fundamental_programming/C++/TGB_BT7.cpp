#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cout << "a=" << '\n';
    cin >> a;
    cout << "b=" << '\n';
    cin >> b;
    cout << "c=" << '\n';
    cin >> c;
    double max_Val = a, min_Val = a;
    if (b > max_Val) {
        max_Val = b;
    } else {
        if (c > max_Val) {
            max_Val = c;
        }
    }
    if (b < min_Val) {
        min_Val = b;
    } else {
        if (c < min_Val) {
            min_Val = c;
        }
    }
    cout << "max=" << max_Val << ",min= " << min_Val << '\n';
}