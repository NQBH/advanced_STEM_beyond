#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        bool yn = false;
        for(int i = 0; i <= n /2020; i++){
            if((n - 2020 * i) % 2021 == 0 || (n-2021 * i) % 2020 == 0){
                yn =true;
                break;
            }
        }
        cout << (yn ? "YES" : "NO") << "\n";
    }
}