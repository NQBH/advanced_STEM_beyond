#include <iostream>
using namespace std;
int m, n;
const double oo = 1e9 + 7;

int main() {
    cin >> m >> n;
    int cnt = 0;
    for (int a = 1; a <= m; ++a) {
        int num = 4 * a * a - 1;
        num = num * num;
        for (int b = 1; b <= n; ++b) {
            int divisor = 4 * a * b - 1;
            if (num % divisor == 0) ++cnt;
        }
    }
    cout << cnt;
}