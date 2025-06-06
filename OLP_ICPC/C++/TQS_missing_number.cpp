#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a[1000005];
    for (long long i = 2; i <= n; i++)
    {
        cin >> a[i];
    }
    long long ssum = (n * (1 + n)) / 2;
    for (long long i = 2; i <= n; i++)
    {
        ssum -= a[i];
    }
    cout << ssum;
}