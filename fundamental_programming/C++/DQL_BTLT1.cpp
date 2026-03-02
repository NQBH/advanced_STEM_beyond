#include <iostream>
using namespace std;

int main() {
    int a, n;

    cin >> a >> n;
    cout << " chung minh "

    cout << "a << n = " << (a << n) << endl;
    cout << "a * 2^n = " << a * (1 << n) << endl;

    cout << "a >> n = " << (a >> n) << endl;
    cout << "a / 2^n = " << a / (1 << n) << endl;

    return 0;
}