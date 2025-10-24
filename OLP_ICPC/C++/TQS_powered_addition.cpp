#include <bits/stdc++.h>
using namespace std;
int n, m, l, a;
main()
{
    for (cin >> a; cin >> n;)
    {
        for (m = 0, l = -INT_MAX; n-- && cin >> a;)
            a < l ? m = max(m, l - a) : l = a;
        cout << (m ? 1 + (int)log2(m) : m) << endl;
    }
}