#include <iostream>
#include <cmath>
using namespace std;
int main () {
    long long M;
    int m;
    int n = 0;
    long long sm = 0;
    cin >> m >> M;
    while (true) {
        long long a = pow(n + 1, m);
        if (sm + a <= M) {
            n++;
            sm += a;
        } else {
            break;
        }
    }
    cout << "n = " << n << endl;
    cout << "Sm= " << sm << endl;
    return 0;
}