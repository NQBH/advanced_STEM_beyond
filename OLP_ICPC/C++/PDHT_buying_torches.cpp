#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--){
        long long x, y, k ;
        cin >> x >> y >> k;
        long long ans = ((k*(y+1)-1)+(x-2))/(x-1);
        cout << ans + k << "\n";
    }
    return 0;
}
