#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0) {
        if ( a == b && b == c) {
            cout << "HLP";
        } else {
            cout << "HHCN" << endl;
            int dienTichXQ = 2 * (a + b) * c;
            cout << dientichXQ << endl;
            int dienTichTP = 2 * (a * b + b * c + a * c );
            cout << dienTichTP << endl;
            double duongcheo = sqrt( a * a + b * b + c * c);
            int TheTich = a * b * c;
            cout << duongcheo << endl;
            cout << TheTich << endl;
        } else {
            cout << -1;
        }
        return 0;
    }
}
