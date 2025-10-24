#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int d, s, k = 1000000000;
        for (int i = 0; i < n; i++){
            cin >> d >> s;
            k = min(k,d + (s-1)/2);
        }
        cout << k << '\n';
    }
    return 0;
}