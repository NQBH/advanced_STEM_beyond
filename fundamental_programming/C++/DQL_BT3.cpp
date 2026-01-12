#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
    }
    else if (a == b && b == c) {
        cout << "HLP";
    }
    else {
        cout << "HHCN" << endl;

        int Sxq = 2 * (a + b) * c;
        int Stp = 2 * (a * b + b * c + a * c);
        float d = sqrt(a * a + b * b + c * c);
        int V = a * b * c;

        cout << Sxq << endl;
        cout << Stp << endl;
        cout << d << endl;
        cout << V;
    }

    return 0;
}