#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x, y, k, kq;
    cin >> n;
    while (n--) {
        kq = 0;
        k = 0;
        cin >> x >> y;
        k = max(x, y);
        k -= 1;
        if (x >= y)
        {
            if (k % 2 != 0)
            {
                kq += (2 * k + 1) - y + 1;
            }
            else
                kq += y;
        }
        else
        {
            if (k % 2 == 0)
            {
                kq += (2 * k + 1) - x + 1;
            }
            else
                kq += x;
        }
        kq += k * k;
        cout << kq << "\n";
    }
}