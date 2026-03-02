#include <iostream>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    double x = -b / a;
    if (a == 0 && b == 0) {
        cout << "INFINITE SOLUTIONS";
    }
    else if (a == 0 && b != 0) {
        cout << "NO SOLUTION";
    }
    else {
        cout << x;
    }
    return 0;
}