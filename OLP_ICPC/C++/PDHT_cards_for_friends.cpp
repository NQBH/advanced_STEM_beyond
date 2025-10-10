#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int w, h, n, sum = 1; cin >> w >> h >>n;
        bool yn = false;
        while(w%2 == 0 || h%2 == 0){
            if(w%2 == 0){
                w = w/2; 
                sum *= 2;
            }
            if(h%2 == 0) {
                h = h/2; 
                sum *= 2;
            }
        }
        if(sum >= n) yn =true;
        if(yn) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
