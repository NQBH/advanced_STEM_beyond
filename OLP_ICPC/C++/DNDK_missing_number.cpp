#include <iostream>
#define ll long long
using namespace std;
int main()
{
    ll n, x;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    ll sum1 = 0;
    for (int i = 0; i < (n - 1); i++) {
        cin >> x;
        sum1 += x;
    }
    cout << sum - sum1;
}