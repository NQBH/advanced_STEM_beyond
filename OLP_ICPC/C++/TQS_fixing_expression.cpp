#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        cout << n[0] << ((n[0] < n[2]) ? '<' : ((n[0] == n[2]) ? '=' : '>')) << n[2] << "\n";
    }
}