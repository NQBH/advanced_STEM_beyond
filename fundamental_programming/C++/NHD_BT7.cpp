#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c;
    cout << "Nhap ba so a,b,c : ";
    cin >> a >> b >> c;

    double maxVal = a;
    double minVal = a;

    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;

    if (b < minVal) minVal = b;
    if (c < minVal) minVal = c;

    cout << "So lon nhat la : " << maxVal << endl;
    cout << "So nho nhat la : " << minVal << endl;

    return 0;
}