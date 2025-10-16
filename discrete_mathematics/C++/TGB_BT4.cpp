#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;

    cout << "so thuc n: ";
    cin >> n;

    if (pow(2, n) >= 100)
        cout << "Bat dang thuc 2^n >= 100 true." << '\n';
    else
        cout << "Bat dang thuc 2^n >= 100 false." << '\n';

    return 0;
}