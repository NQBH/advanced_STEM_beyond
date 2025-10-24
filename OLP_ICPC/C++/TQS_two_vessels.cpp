#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    double a,b,c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        cout << ceil(abs(((a+b)/2) - min(a,b))/c)<< "\n";
    }
}
