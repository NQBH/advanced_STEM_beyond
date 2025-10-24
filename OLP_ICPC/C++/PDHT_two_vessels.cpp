#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        long long ans = abs(a-b);
        long long move = (ans+2*c-1)/(2*c);
        cout << move << "\n";
    }
}