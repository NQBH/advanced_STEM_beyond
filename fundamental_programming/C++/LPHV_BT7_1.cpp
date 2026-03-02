#include<iostream>
using namespace std;
int main () {
    double a, b, c;
    cin >> a >> b >> c;
    double min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    double max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    cout << min << " " << max;
}