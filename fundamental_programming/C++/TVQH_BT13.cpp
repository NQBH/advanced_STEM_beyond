#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int n, m, M;
    double s = 0;
    cout << "Nhap n va m va M:";
    cin >> n >> m >> M;
    int i;
    for (i = 1; i <= n ; i++) {
        double s2 = pow(i, m);
        if (s + s2 <= M) {
            s = s + s2;
        } else {
            break;
        }
    }
    cout << "S = " << s;
    return 0;
}
