#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        long long n, m, x, y, tmp;
        cin >> n >> m >> x >> y;
        for(int i = 0; i < n; i++) cin >> tmp; 
        for(int i = 0; i < m; i++) cin >> tmp; 
        cout << n + m << '\n';
    }
}