#include <iostream>
#include <cmath>
using namespace std;
long long a, b;
const double oo = 1e9 + 7;

int main() {
    long long cnt = 0;
    cin >> a >> b;
    for (long long i = a; i <= b; ++i) {
        long long new_num = i * i + 1;
        double limit = 2.0 * i + sqrt(2 * i);
        long long temp = new_num;
        bool ok = false;
        for (long long j = 2; j * j <= new_num; ++j)
            if (temp % j == 0) {
                while (temp % j == 0) temp /= j;
                if (j > limit) {
                    ok = true;
                    break;
                }
            }
        if (!ok && temp > 1 && temp > limit) ok = true;
        if (ok) ++cnt;
    }
    cout << cnt;
}