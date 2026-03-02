#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double maxVal, minVal;

    // Tìm max
    if (a >= b && a >= c)
        maxVal = a;
    else if (b >= a && b >= c)
        maxVal = b;
    else
        maxVal = c;

    // Tìm min
    if (a <= b && a <= c)
        minVal = a;
    else if (b <= a && b <= c)
        minVal = b;
    else
        minVal = c;

    cout << "Max = " << maxVal << endl;
    cout << "Min = " << minVal << endl;

    return 0;
}
