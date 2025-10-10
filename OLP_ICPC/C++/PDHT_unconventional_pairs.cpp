#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n; i+=2) {
            int curr_ans = a[i+1] - a[i];
            if(curr_ans > ans) ans = curr_ans;
        }
        cout << ans << "\n";
    }
}
