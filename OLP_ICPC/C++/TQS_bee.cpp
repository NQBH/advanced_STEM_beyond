#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n != -1)
    {
        long long a = 1, b = 0;
        for (int i = 0; i < n; i++)
        {
            long long c, d;
            c = 1 + b;
            d = a + b;
            a = c;
            b = d;
        }
        cout << b << ' ' << a + b << endl;
        cin >> n;
    }
}
