#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    if (r>n-r) r=n-r;
    long long res=1;
    for(int i=1; i<=r; i++) {
        res*=(n-r+i);
        res/=i;
    }
    return res;
}

long long veTrai(int n) {
    long long res=0.0;
    for(int i=0; i<=n; i++) {
        res+=nCr(n,i)*nCr(n,i) ;
    }
    return res;
}

long long vePhai(int n) {
    return nCr(2*n,n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    cout<<"Ve trai = " << veTrai(n) << '\n';
    cout<<"Ve phai = " << vePhai(n);
}
