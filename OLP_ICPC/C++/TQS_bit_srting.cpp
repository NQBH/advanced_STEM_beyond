#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    unsigned long tong = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        tong = (tong * 2) % 1000000007;
    cout << tong ;
}