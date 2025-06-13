#include <iostream>
using namespace std;

int main() {
    int m, n, kq = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (((4 * i * i - 1) * (4 * i * i - 1)) % (4 * i * j - 1) == 0) ++kq;
    cout << kq;
}