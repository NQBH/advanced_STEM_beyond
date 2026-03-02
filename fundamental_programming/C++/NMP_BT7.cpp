#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    double a, maxVal, minVal;
    cin >> a;
    maxVal = minVal = a;

    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a > maxVal) maxVal = a;
        if (a < minVal) minVal = a;
    }

    cout << "lon nhat = " << maxVal << endl;
    cout << "nho nhat = " << minVal << endl;
    return 0;
}