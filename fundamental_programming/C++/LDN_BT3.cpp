#include <cmath>
#include <iostream>
using namespace std;
int main() {
    long long a, b, c;
    cout << "nhap 3 so nguyen a,b,c:";
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << "HLP" << endl;
    } else {
        cout << "HHCN" << endl;
    }
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
        return 0;
    }
}