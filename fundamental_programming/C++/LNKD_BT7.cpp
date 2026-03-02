#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n: ";
    cin >> n;

    double a;
    cout << "so thuc 1: ";
    cin >> a;
    double maxVal = a;
    double minVal = a;

    for (int i = 2; i <= n; i++) {
        cout << "so thuc " << i << ": ";
        cin >> a;

        if (a > maxVal)
            maxVal = a;

        if (a < minVal)
            minVal = a;
    }
    cout << "\nlon nhat = " << maxVal << endl;
    cout << "nho nhat = " << minVal << endl;

    return 0;
}