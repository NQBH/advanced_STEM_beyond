#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long tong = 0;
    while (n >= 5)
    {
        tong += n / 5;
        n = n / 5;
    }
    cout << tong;
}